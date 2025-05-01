#include <algorithm>
#include <iostream>
#include <random>
#include <set>


//copied from https://en.cppreference.com/w/cpp/container/set
// overloading << operator for sets
template<typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set)
{
    if (set.empty())
        return out << "{}";
    out << "{ " << *set.begin();
    std::for_each(std::next(set.begin()), set.end(), [&out](const T& element)
    {
        out << ", " << element;
    });
    return out << " }";
}


void printSet(std::set<int>::iterator it1, std::set<int>::iterator it2)
{
    std::cout << "{ ";
    for (; it1 != it2; it1++)
    {
        std::cout << *it1 << ", ";
    }
    std::cout << "}";
}

// want two pointers that sepcify intervals

std::set<int>::iterator test(std::set<int>::iterator lbound, std::set<int>::iterator ubound)
{
    int tmp = *lbound;
    for (; lbound != ubound; lbound++)
    {
        if ((*lbound- tmp) > 1) 
        {
            return lbound;
        }
        tmp =  *lbound;
        printf("%d", tmp);
    }
    return ubound;
}

int main(void)
{
    const int npoints = 8;
    int points[npoints];
    std::random_device rd;    
    std::uniform_int_distribution<int> dist(0, 9);
    
    std::set<int> set;

    for (int i=0; i< npoints; i++)
    {
        points[i] = dist(rd);
        set.insert(dist(rd));
        
    }

    std::set<int>::iterator interval = test(set.begin(), set.end());
    
    printSet( set.begin(), set.end()); 
    printSet( set.begin(), interval); 
    auto i2 = test(interval, set.end());
    std::cout << "\n";


    std::cout << set << "\n";
   
}
