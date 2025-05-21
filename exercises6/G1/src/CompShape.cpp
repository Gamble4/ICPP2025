#include "CompShape.hpp"
#include "shape.hpp"



bool compShape::compareAreas(Shape *s1, Shape *s2)
{
    if (s1->getArea() < s2->getArea())
    {
        return true;
    }
    return false;
};


float Rectangle::getArea() 
{
    return m_height * m_width;
}

float Triangle::getArea()
{
    return m_height * m_width / 2;
}

float Circle::getArea()
{
    return m_radius * m_radius * 3.1415;
}
