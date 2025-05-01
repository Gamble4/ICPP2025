#include "src/B3_header.h"
#include "src/mt19937.h"

#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>
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


// generates a normalized [0, 1] random number from the MT19937 generator
double mt19937_rand_n(MT19937* generator)
{
    uint32_t val = mt19937_rand( generator);
    double vald = val * (1.0 / std::numeric_limits<uint32_t>::max());
    return vald;
}

 // T defined in meresenne-twister header
 template<typename TT>
 void write_2col(std::basic_ofstream<char>& s, TT& e1, TT& e2, int pad_len=20)
 {
 
     s << std::setw(pad_len) << std::setfill(' ') << e1
       << std::setw(pad_len) << std::setfill(' ') << e2
       << "\n";
}

// overloaded version for direct input
template<typename TT>
void write_2col(std::basic_ofstream<char>& s, TT e1, TT e2, int pad_len=20)
{
 
     s << std::setw(pad_len) << std::setfill(' ') << e1
       << std::setw(pad_len) << std::setfill(' ') << e2
       << "\n";
}
 
int main(void)
{
    MT19937 mt19937_self = mt19937_seed(12345);
    
    std::string fname;    
    int num_points, num_inside = 0;


    std::cout << "Please enter the number of points to be used and a filename in which to store the data \n";
    std::cin >> num_points >> fname;
    std::cout << "npoints:  " <<  num_points << ", " 
              << "filename: " << fname << "\n";

    if (num_points <=0)
    {
        std::cout << "please enter a positive integer \n";
        throw -1;
    }

    std::ofstream File(fname);
    write_2col(File, "# num points" , "pi approximation");
    
    std::vector<Circle_w_ctor> vC;
    Circle center = {{0., 0.}, 0.};
    Circle c_tmp = {{0., 0.}, 0.};
    vC.reserve(num_points);
    for (int i=0; i<num_points; ++i)
    {
        vC.emplace_back(
            mt19937_rand_n(&mt19937_self),
            mt19937_rand_n(&mt19937_self),
            0.);      
            
        c_tmp.center.x = mt19937_rand_n(&mt19937_self);
        c_tmp.center.y = mt19937_rand_n(&mt19937_self);

            
        if (circ_center_to_center(&c_tmp, &center) < 1)
        {
            num_inside++;
        };

        write_2col<double>(File, i, 4*(double) num_inside/num_points);
        
    }

    File.close();

}
