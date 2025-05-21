#include <iostream>

class dummyC
{
private:
    static int m_numdummyC;
};

class myObj
{
private:
    int m_a;    

public:
    static int m_instances;
    int p_a;
    myObj(int a) : m_a {a}, p_a {a} // <-- this assignment {} performs strong type checking
    {std::cout << "nr objects: " << ++m_instances << " \n";}

    void print() {std::cout << m_a << " " << p_a << "\n"; }
    const int& get_a() {return m_a;}     
    myObj* get_ptr()  {return this;}
    myObj& get_ref()  {return *this;}
    static void print_nr_instances() { std::cout << "nr objects: " << m_instances << " \n";}
    

    ~myObj() 
    {std::cout << "nr objects: " << --m_instances << " \n";}
};

int myObj::m_instances = 0;
int dummyC::m_numdummyC = 12;

void change_pa(myObj *obj)
{
    obj->p_a = 99;
}

void change_pa(myObj &obj)
{
    obj.p_a = 99;
}

int main() {

    // funktioniert, obwohl keine Objekte dieser Klasse existieren, kann aber nur
    // andere statics sehen
    myObj::print_nr_instances();

    myObj obj{1};
    myObj obj2{2};
    myObj obj3{3};
    
    std::cout << obj.get_a() << "\n";
    int myObj::* pa = &myObj::p_a;
    obj.*pa = 17;
    obj.print();

    change_pa(obj2.get_ref());
    obj2.get_ptr()->print();
    
    return 0;
}