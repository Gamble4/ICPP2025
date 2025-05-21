#include "shape.hpp"
#include <string>

std::string Shape::getName() {
   return name;
}

std::string Shape::getInfo() {
   return "I'm a " + name + " of area " + std::to_string(getArea());
}
