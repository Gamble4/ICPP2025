#include <iostream>
class A {
private:
int a;
public:
A(int x) { a = x; }
// custom constructor
int getA() { return a; } };
class B {
private:
const int x;
// constant attribute
int &b;
// reference attribute
A objA;
// object attribute (custom constructor)
public:
// v-- instead of this->x
B(int x, int &y): b(y), x(x), objA(++x) {}
void print() {
std::cout << "B.x: " << x << ", B.b: " << b;
std::cout << ", A.a: " << objA.getA() << std::endl;
} };
int main() {
int bb = 20; B myB(10, bb);
myB.print();
// output: B.ct: 10, B.b: 20, A.a: 11
bb = 30;
myB.print();
// output: B.ct: 10, B.b: 30, A.a: 11
}