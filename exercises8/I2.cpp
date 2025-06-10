#include <memory>
#include <stdexcept>
#include <vector>
#include <iostream>

/*

(1, 2, 7, 1, 0, 2, 4, 5)
 ^     ^  ^  

(1, 7, 1) <- analysis eg. average of subgroup

*/


class Analyzer
{
private:
    std::vector<int> m_data;
public:
    Analyzer() {};

    void add_element(int const& x) {m_data.push_back(x);}
    double get_average() const
    {
        if (m_data.size() == 0) {throw std::length_error("average of vector of size 0");}
        
        double out=0;
        for (int const& x : m_data) { out += x;}
        return out/m_data.size();
    }
};

class Classifier
{
private:    
    std::shared_ptr<Analyzer> m_p_even;
    std::shared_ptr<Analyzer> m_p_odd;
    std::vector<std::shared_ptr<Analyzer>> m_ptrs{m_p_even, m_p_odd}; // has a copy 
public:

    // the first pointer gets the even elements
    // the second pointer gets the odd elements
    Classifier(std::shared_ptr<Analyzer> p1, std::shared_ptr<Analyzer> p2) :
    m_p_even(p1), m_p_odd(p2) // copy the shared pointers
    {}

    void classify_int(int x) const
    {
        if (x%2 == 0) 
        {
            m_p_even->add_element(x);
        }
        else
        {
            m_p_odd->add_element(x);
        }
    }

    void classify_int_sequence(std::vector<int>& v) const
    {
        for (int& x : v) { classify_int(x);}
    }

    // not sure what is best here, reference to unique pointers, 
    // reference to shared or copy of shared, all work
    std::shared_ptr<Analyzer>& get_ptr_even() { return m_p_even;}
    std::shared_ptr<Analyzer>& get_ptr_odd()  { return m_p_odd;}
    auto& get_ptrs() {return m_ptrs;}

};



int main()
{
    // expected:
    // 1 + 5 + 9 + 3  = 18 / 4 = 4.5;
    // 2 + 4 + 8 + 14 + 4 = 32 / 5 = 6.4
    std::vector<int> testseq = {1, 2, 5, 4, 9, 3, 8, 4};
    std::shared_ptr<Analyzer> Even_ptr, Odd_ptr;
    Even_ptr = std::make_shared<Analyzer>();
    Odd_ptr = std::make_shared<Analyzer>();

    {
        Classifier C{Even_ptr, Odd_ptr};
        C.classify_int_sequence(testseq);
        C.classify_int(14);
        
    } // <- Classifier destructor is called here, C does not exist after this 

    double av_even = Even_ptr->get_average();
    double av_odd = Odd_ptr->get_average();
    
    std::cout << "av even " << av_even << "\n";
    std::cout << "av odd " << av_odd << "\n";   
        

    //std::cout << C.get_ptr_odd().use_count() << "\n"; // testing
    //std::cout << C.get_ptr_even().use_count() << "\n";
}