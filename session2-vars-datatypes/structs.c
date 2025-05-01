#include <stdio.h>
#include <math.h>

// typedef for easiers creation
typedef struct VecBase
{
    double x, y, z;

} VecBase;


double VecBase_dot(VecBase* v1, VecBase* v2)
{
    return v1->x * v2-> x + v1->y * v2->y + v1->z * v2-> z;
}

double VecBase_len(VecBase* v)
{
    return sqrt((VecBase_dot(v, v)));
}


int main()
{
    VecBase v1 = {.x=3., .y=4., .z=0};
    
    printf("%lf \n", VecBase_len(&v1));
}
