#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

class Shape {
   protected:
      std::string name;
   public:
      Shape(std::string n):name(n) {}
      virtual ~Shape() {};
      virtual float getArea() = 0;
      std::string getName();
      std::string getInfo();
};

#endif
