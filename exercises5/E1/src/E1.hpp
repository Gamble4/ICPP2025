#ifndef MY_QUATERNIONS_IMP
#define MY_QUATERNIONS_IMP

typedef struct quaternion
{
    double m_w, m_x, m_y, m_z;
    quaternion(double w, double x, double y, double z) :
    m_w {w}, m_x {x}, m_y{y}, m_z{z}
    {};
    quaternion operator+(quaternion& q);
    quaternion operator-(quaternion& q);
    
} quaternion;

void printQuaternion(quaternion& q);
void printQuaternion(quaternion&& q);

#endif