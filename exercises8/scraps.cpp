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
    double get_average()
    {
        double out=0;
        if (m_data.size() == 0) {throw std::length_error("average of vector of size 0");}
        
        for (int& x : m_data) { out += x;}
        return out/m_data.size();
    }
};

class Classifier
{
private:
    std::unique_ptr<Analyzer> m_p_even = std::make_unique<Analyzer>();
    std::unique_ptr<Analyzer> m_p_odd = std::make_unique<Analyzer>();
    //std::vector<std::unique_ptr<Analyzer>> m_ptrs{m_p_even, m_p_odd};
public:

    Classifier() {};

    void classify_int(int& x)
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

    void classify_int_sequence(std::vector<int>& v)
    {
        for (int& x : v) { classify_int(x);}
    }

    std::unique_ptr<Analyzer>& get_ptr_even() { return m_p_even;}
    std::unique_ptr<Analyzer>& get_ptr_odd() { return m_p_odd;}

};

int main()
{
    std::vector<int> testseq = {1, 2, 5};
    Analyzer A;
    Classifier C;

    C.classify_int_sequence(testseq);



    //double av_even = C.get_ptr_even()->get_average();
    double av_odd = C.get_ptr_odd()->get_average();

    std::cout << C.get_ptr_even() << "\n";
    
    //std::cout << "av even " << av_even << "\n";
    std::cout << "av odd " << av_odd << "\n";

}