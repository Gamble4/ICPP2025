#include <iostream>
#include <memory>


struct A {
int a;
A(int a):a{a} {} };
int main(){
std::unique_ptr<A> a1(new A(3)), a2;
// or auto a1 = std::make_unique<Asm>(3);
std::cout << a1->a << std::endl;
a2 = std::move(a1);
// moveable
std::cout << a2->a << std::endl;
if (a1) { std::cout << a1->a << std::endl; }
else { std::cout << "a1 not valid anymore" << std::endl; }
A* a3 = a2.release();
if (a2) { std::cout << a2->a << std::endl; }
else { std::cout << "a2 not valid anymore" << std::endl; }
std::cout << a3->a << std::endl; }