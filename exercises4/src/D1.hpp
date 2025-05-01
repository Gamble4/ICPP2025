#include <set>

#ifndef D1_HEADER
#define D1_HEADER

void printSet(std::set<int>::iterator it1, std::set<int>::iterator it2);
void printInterval(std::set<int>::iterator it1, std::set<int>::iterator it2);


/**
* Coherent as in neighbouring elements have their differences = 1, t_j - t_i == 1, t_j > t_i
*/
std::set<int>::iterator findCoherentSet(std::set<int>::iterator lbound, std::set<int>::iterator ubound);

#endif 
