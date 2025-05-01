#include "src/D1.hpp"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>


int main(void)
{
    const int npoints = 8;    
    std::random_device rd;    
    std::uniform_int_distribution<int> dist(0, 9);
    
    std::set<int> set;

    for (int i=0; i< npoints; i++)
    {        
        set.insert(dist(rd));       
    }

    std::set<int>::iterator found_ubound, lbound = set.begin();
    std::cout << "entire set: \n";
    printSet( set.begin(), set.end()); 
    std::cout << "\n";

    for (;lbound != set.end();)
    {
        found_ubound = findCoherentSet(lbound, set.end());
        std::cout << "subset: ";        
        printSet( lbound, found_ubound);
        std::cout << " interval: ";
        printInterval(lbound, --found_ubound);
        std::cout << "\n";
        lbound = ++found_ubound;
    }
    
}
