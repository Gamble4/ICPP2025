#include "shape.hpp"
#ifndef COMPSHAPE_H
#define COMPSHAPE_H

class compShape : public Shape
{
public:
    compShape(std::string name) : Shape(name) {};
    static bool compareAreas(Shape* s1, Shape* s2);
    virtual ~compShape() {};
};

class Rectangle : public compShape
{
private:
    float m_height;
    float m_width;
public:
    Rectangle(float height, float width) :compShape("Rectangle"),
    m_height(height), m_width(width)    
    {};

    float getArea() override;
    
};

class Triangle : public compShape
{
private:
    float m_height;
    float m_width;
public:
    Triangle(float height, float width) :compShape("Triangle"),
    m_height(height), m_width(width)    
    {};

    float getArea() override;
    
};


class Circle : public compShape
{
private:
    float m_radius;
public:
    Circle(float radius) :compShape("Circle"),
    m_radius(radius)   
    {};

    float getArea() override;
    
};


#endif