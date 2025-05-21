#include <iostream>

class A {
   private:
   public:
   int z, y, x;
      A(int a, int b) : x{b}, z{x * x}, y(a) {}
};

A obj(1, 2);
int main() {

   A obj(1, 2);

   std::cout << obj.x << obj.z << obj.y;

}