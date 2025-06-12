#include <iostream>


int main() {

   
    std::cout << "Hello, World!" << "\n";



   int a{1};
   constexpr int b{2};
   static int c{3};
   int d{4};

   [d](){


      std::cout << c << d << b;
      d;
   }();
}
