#include <iostream>
#include <algorithm>


typedef class CSI {
private:
    int * a;
    int b;
public:
CSI(int value, int b) { a = new int(value); this->b = b; }
CSI(const CSI& obj):a(new int(*obj.a)), b(obj.b) {}
// custom copy ctr.
friend void swap(CSI& obj1, CSI& obj2) 
{
    // allow for...
    using std::swap;
    // ... argument-dependent lookup (ADL)... // ... of the actual swap function
    // every attribute requires its own swap, otherwise it wont be exchanged
    // control the copy of certain attributes
    swap(obj1.a, obj2.a);
    swap(obj1.b, obj2.b); }

CSI& operator=(CSI obj)
{
    // argument passed by value
    swap(*this, obj);
    // swapping resources
    return *this;
}
~CSI() { delete a; }
// destructor, clean up
void print() { std::cout << "a: " << *a << " b: " << b << std::endl; }
} CSI;

int main()
{
    CSI obj1(100, 10), obj2(2, 5);
obj2.print();
// output: a: 2
obj2 = obj1;
obj2.print();
// output: a: 100
}