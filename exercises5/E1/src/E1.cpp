#include "E1.hpp"
#include <iostream>

quaternion quaternion::operator+(quaternion& q)
{
    return quaternion{m_w+q.m_w, m_x+q.m_x, m_y+q.m_y, m_z+q.m_z};
}

quaternion quaternion::operator-(quaternion& q)
{
    return quaternion{m_w-q.m_w, m_x-q.m_x, m_y-q.m_y, m_z-q.m_z};
}


void printQuaternion(quaternion& q)
{
    std::cout << q.m_w << " + " << q.m_x << "i + " << q.m_y << "j + " << q.m_z << "k \n";
}

void printQuaternion(quaternion&& q)
{
    std::cout << q.m_w << " + " << q.m_x << "i + " << q.m_y << "j + " << q.m_z << "k \n";
}
