#include "src/atoms.hpp"
#include <vector>
#include <iostream>

int main()
{
    Atom Fe{"Fe", 55, 26};
    
    Particle pq{"quark", 1, 0, 1./2};
    Nucleus nuc{55, 26};
    
    pq.printInfo();
    nuc.printInfo();

    Atom Ag{"Ag", 26, 11};
    Atom He{"He", 1, 1};

    He.printInfo();

    std::vector<Atom> vAtom{Fe, Ag, He};
    const unsigned int t = 1;
    const unsigned int& tr = t;
    std::cout << (int) tr* -1 << "\n";
    

}