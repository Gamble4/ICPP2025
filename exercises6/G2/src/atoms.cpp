#include "atoms.hpp"
#include <iostream>

// Nucleus
Nucleus::Nucleus(unsigned int A, unsigned int Z) :    
m_Neutrons{Particle("Neutrons", A-Z,  0, 1./2)},
m_Protons {Particle("Protons", Z, 1, 1./2)}    
    {};

Particle const& Nucleus::getNeutrons() const {return m_Neutrons;}
Particle const& Nucleus::getProtons() const {return m_Protons;}

void Nucleus::printInfo() const
{
    std::cout << "Nucleus Info:"
    << "Neutron amount: " << m_Neutrons.getAmount()
    << " Proton amount: " << m_Protons.getAmount()
    << " Total Charge: " <<  (int) m_Protons.getAmount() * m_Protons.getCharge() << "\n";
}


// Particle
Particle::Particle(std::string name, unsigned int amount, int charge, float spin) :
m_name{name}, m_amount{amount}, m_charge{charge}, m_spin{spin}
{};

std::string const& Particle::getName() const {return m_name;}
unsigned int const& Particle::getAmount() const {return m_amount;}
int const& Particle::getCharge() const {return m_charge;}
float const& Particle::getSpin() const {return m_spin;}

void Particle::printInfo() const
{
    std::cout << "Particle Info: "
    <<  m_name
    << " amount: " << m_amount    
    << " Total Charge: " << (int) m_amount * m_charge
    << " Spin: "  << m_spin << "\n";
}


// Atom
Atom::Atom(std::string name, unsigned int A, unsigned int Z) :
m_name{name}, m_A{A}, m_Z{Z},
m_Nucleus(Nucleus(A, Z)),
m_Electrons(Particle("Electrons", Z,  -1, 1./2))
{};

std::string const& Atom::getName() const {return m_name;}
Particle const& Atom::getNeutrons() const {return m_Nucleus.getNeutrons();}
Particle const& Atom::getProtons() const {return m_Nucleus.getProtons();}
Particle const& Atom::getElectrons() const {return m_Electrons;}
Nucleus  const& Atom::getNucleus() const {return m_Nucleus;}

void Atom::printInfo() const
{
    std::cout << "-- Atom Info -- \n"
    << "name: " << m_name
    << " A: " << m_A 
    << " Z: " << m_Z << "\n";
    m_Nucleus.printInfo();
    m_Electrons.printInfo();
    std::cout << "-- end -- " << std::endl;
}


// testing with molecule
Molecule::Molecule(std::string name, std::vector<Atom>& vAtom) :
m_name {name}, m_vAtoms {vAtom}
{
    m_A = 0;
    m_charge = 0;
    for (Atom& a : m_vAtoms)
    {
        m_A += a.getProtons().getAmount() + a.getNeutrons().getAmount();
        m_charge += (a.getProtons().getAmount() * a.getProtons().getCharge() + 
                     a.getElectrons().getAmount() * a.getElectrons().getCharge());
    }
}

Molecule::Molecule(std::string name, std::vector<Atom>&& vAtom) :
m_name {name}, m_vAtoms {vAtom}
{
    m_A = 0;
    m_charge = 0;
    for (Atom& a : m_vAtoms)
    {
        m_A += a.getProtons().getAmount() + a.getNeutrons().getAmount();
        m_charge += (a.getProtons().getAmount() * a.getProtons().getCharge() + 
                     a.getElectrons().getAmount() * a.getElectrons().getCharge());
    }
}


int const& Molecule::getCharge() const {return m_charge;}

Atom const* Molecule::begin() const {return &m_vAtoms[0];}
Atom const* Molecule::end() const {return &m_vAtoms[m_vAtoms.size()];}