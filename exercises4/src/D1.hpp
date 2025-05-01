#include <set>

#ifndef D1_HEADER
#define D1_HEADER


/**
* Streams the Set described by two iterators to the standard output std::cout
* @param[lbound] the iterator correspoding to the lower bound of the set
* @param[ubound] the iterator correspoding to the upper bound of the set
*/
void printSet(std::set<int>::iterator lbound, std::set<int>::iterator ubound);

/**
* Streams an interval representation described by two iterators to the standard output std::cout
* @param[lbound] the iterator correspoding to the lower bound of the set
* @param[ubound] the iterator correspoding to the upper bound of the set
*/
void printInterval(std::set<int>::iterator lbound, std::set<int>::iterator ubound);

/**
* Returns the iterator to the next element after the coherent set has ended
* The sorted set \f$s\f$ is coherent as in for Elements \f$t_i, \in s, ~ t_{i+1} > t_i, ~ t_{i+1} - t_i = 1 \f$
* @param[lbound] the iterator correspoding to the lower bound of the set
* @param[ubound] the iterator correspoding to the upper bound of the set
*/
std::set<int>::iterator findCoherentSet(std::set<int>::iterator lbound, std::set<int>::iterator ubound);

#endif 
