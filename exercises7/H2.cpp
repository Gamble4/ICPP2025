#include <iostream>
#include <string>
#include <type_traits>
#include <concepts>


template<typename... Types>
void print(Types&&... args)
{
    (std::cout << ... << args) << "\n";
}

template<class T> concept method_to_string_viable
= requires(T a)
{
    a.to_string(); 
    requires std::same_as<std::string, decltype(a.to_string())>; 
};

class dummyClass
{
private:
    int m_var;
public:
    dummyClass(int var) : m_var(var) {};
    // explicitly set a to_string() method for testing
    std::string to_string() {return std::to_string(m_var);}
};

class takeAll
{
private:
    std::string m_var;
public:       

    // std::to_string("string") fails, therefore directly provided string support
    takeAll(std::string var) : m_var(var) {};

    // commented out since this creates ambiguity with the later defined constructor
    //template<std::integral T>
    //takeAll(T var) : m_var(std::to_string(var))
    //{print("called takeAll integral");};    

    template<class T> requires method_to_string_viable<T>
    takeAll(T var) : m_var(var.to_string())
    {print("called takeAll Class");};    

    template<typename T>
    requires requires (T var) {std::to_string(var); std::constructible_from<std::string, T>;}
    takeAll(T var) : m_var(std::to_string(var))
    {print("called takeAll type");};    


    const std::string& getVar() const {return m_var;}
};



int main()
{
    
    takeAll T1(1);
    takeAll T2(1.3);
    
    dummyClass D(34);
    takeAll T3(D);

    takeAll T4('x');

    takeAll TT("string");
    
    print(T1.getVar(), " \n", T2.getVar(), "\n", T3.getVar(), "\n", T4.getVar());
}