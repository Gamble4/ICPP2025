#include <math.h>
#include <stdio.h>

#ifndef B3_HEADER_IMP
#define B3_HEADER_IMP

#define B3_PI 3.1415926535

typedef struct Point
{
    double x;
    double y;
} Point;

typedef struct Circle
{
    Point center;
    const double radius;
} Circle;

enum IntersectionPoints
{
    NONE, 
    ONE, 
    TWO
};

double circ_perimeter(Circle*);
double circ_area(Circle*);
double circ_center_to_center(Circle*, Circle*);
double circ_radical_line(Circle*, Circle*);
int circ_intersec_points(Circle*, Circle*);


double circ_perimeter(Circle *c)
{
    return 2*B3_PI*(c->radius);
}

double circ_area(Circle *c)
{
    return B3_PI * c->radius * c->radius;
}

double circ_center_to_center(Circle *c1, Circle *c2)
{
    double xdist = (c1->center.x - c2->center.x);
    double ydist = (c1->center.y - c2->center.y);

    return sqrt(xdist*xdist + ydist*ydist);    
}

int circ_intersec_points(Circle *c1, Circle *c2)
{
    double det, d, r, R;
    r = c2->radius;
    R = c1->radius;
    d = circ_center_to_center(c1, c2);

    // overlap
    if ((d == 0) && (r == R))
    {
        return -1;
    }
    
    det = (-d+r-R)*(-d-r+R)*(-d+r+R)*(d+r+R);
    if (det > 0) return TWO;
    if (det == 0) return ONE;
    return NONE;
}

double circ_radical_line(Circle *c1, Circle *c2)
{
    if (circ_intersec_points(c1, c2) != TWO) return 0;

    double det, d, r, R;
    r = c2->radius;
    R = c1->radius;
    d = circ_center_to_center(c1, c2);
    det = (-d+r-R)*(-d-r+R)*(-d+r+R)*(d+r+R);
    return 1/d * sqrt(det);
}

#endif
