#include "src/E1.hpp"
int main()
{
    quaternion q1{1, 1, 1, 1};
    quaternion q2{1, 2, 3, 4};
    
    printQuaternion(q1);
    printQuaternion(q1+q2);
    printQuaternion(q1-q2);

}