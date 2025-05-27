#include "src/atoms.hpp"
#include <vector>
#include <iostream>

// in kg
double AtomMass(Atom& atom)
{
    return (atom.getNeutrons().getAmount() + atom.getProtons().getAmount()) * 1e-26;
}

int main()
{
    
    Atom Protium{"Protium", 1, 1};
    Atom Deuterium{"Deuterium", 2, 1};
    Atom Tritium{"Tritium", 3, 1};

    std::vector<Atom> vAtom{Protium, Deuterium, Tritium};
    for (Atom& a : vAtom)    
    {
        a.printInfo();        
    }

    Protium.getElectrons().printInfo();
    Protium.getNeutrons().printInfo();
    Protium.getProtons().printInfo();

    Protium.getNucleus().getProtons().printInfo();
    Protium.getNucleus().getNeutrons().printInfo();

    Particle Electron{"Electron", 1, -1, 1./2};
    Particle Proton{"Proton", 1, 1, 1./2};
    Particle Neutron{"Neutron", 1, 0, 1./2};

    Electron.printInfo();
    Proton.printInfo();
    Neutron.printInfo();

    std::cout << "molecule test \n";
    // try water molecule
    Atom Hydrogen{"Hydrogen", 1, 1};
    Atom Oxygen("Oxygen", 16, 8);

    Molecule WaterMol{"WaterMol", std::vector<Atom>{Hydrogen, Hydrogen, Oxygen}};
    for (Atom a : WaterMol)
    {
        a.printInfo();
    }
    std::cout <<  WaterMol.getCharge() << "\n";     
}
