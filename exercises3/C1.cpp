#include "src/B3_header.h"
#include "src/mt19937.h"

#include <stdio.h>
#include <limits>
#include <vector>

typedef struct Circle_w_ctor 
{
    Point center = {0., 0.};
    const double radius = 0.;

    Circle_w_ctor() = default;
    Circle_w_ctor(double x, double y, double radius) :
    center{x, y} , radius (radius)
    {}
}Circle_w_ctor;



double create_normalized_rand(MT19937* generator)
{
    uint32_t val = mt19937_rand( generator);
    double vald = val * (1.0 / std::numeric_limits<uint32_t>::max());
    return vald;
}

int main(void)
{
    MT19937 mt19937_self = mt19937_seed(12345);
    
    const int num_points = 1e6;
    int num_inside = 0;
    std::vector<Circle_w_ctor> vC;
    Circle center = {{0., 0.}, 0.};
    Circle c_tmp = {{0., 0.}, 0.};
    //vC.reserve(num_points);
    for (int i=0; i<num_points; ++i)
    {
        //vC.emplace_back(
        //    create_normalized_rand(&mt19937_self),
        //    create_normalized_rand(&mt19937_self),
        //    0.);      
            
        c_tmp.center.x = create_normalized_rand(&mt19937_self);
        c_tmp.center.y = create_normalized_rand(&mt19937_self);

            
        if (circ_center_to_center(&c_tmp, &center) < 1)
        {
            num_inside++;
        };
    }

    printf("mc pi with %d points: %lf \n", num_points, 4 * (double) num_inside / num_points);

}
