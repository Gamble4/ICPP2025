#include "D1.hpp"
#include <iostream>
#include <set>


void printSet(std::set<int>::iterator it1, std::set<int>::iterator it2)
{
    std::cout << "{ ";
    for (; it1 != it2; it1++)
    {
        std::cout << *it1 << ", ";
    }
    std::cout << "}";
}


void printInterval(std::set<int>::iterator it1, std::set<int>::iterator it2)
{
    std::cout << "[ " << *it1 << ", " << *it2 << " ]";
}


std::set<int>::iterator findCoherentSet(std::set<int>::iterator lbound, std::set<int>::iterator ubound)
{
    int tmp = *lbound;
    for (; lbound != ubound; lbound++)
    {
        if ((*lbound- tmp) > 1) 
        {
            return lbound;
        }
        tmp =  *lbound;        
    }
    return ubound;
}
