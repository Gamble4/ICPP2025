#include <memory>
#include <iostream>

template<typename... Types>
void print(Types&&... args)
{
    (std::cout << ... << args) << "\n";
}

class A
{
private:
    int m_val;
public:
    A(int a) : m_val {a} 
    {}

    int& get_val() { return m_val;}
};


int copy_val(std::weak_ptr<A> wptr)
{
    if (wptr.expired()) {throw std::bad_weak_ptr();}
    return wptr.lock()->get_val();
}

int main()
{
    std::shared_ptr<A> sptr_A;
    std::weak_ptr<A>   wptr_A;

    sptr_A = std::make_shared<A>(5); // args are passed to the constructor of A
    wptr_A = sptr_A;

    print("locked weak ptr: ", wptr_A.lock()->get_val());
    
    //wptr_A.reset(); // <-- expires the pointer
    if (wptr_A.expired()) {print("weak ptr expired");};


}