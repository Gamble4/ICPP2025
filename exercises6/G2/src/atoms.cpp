#include "atoms.hpp"
#include <iostream>

// Nucleus
Particle const& Nucleus::getNeutrons() const {return m_Neutrons;}
Particle const& Nucleus::getProtons() const {return m_Protons;}

void Nucleus::printInfo() const
{
    std::cout << "Nucleus Info:"
    << "Neutron amount: " << m_Neutrons.getAmount()
    << " Proton amount: " << m_Protons.getAmount()
    << " Total Charge: " <<  ((int) m_Protons.getAmount()) * m_Protons.getCharge() << "\n";
}


// Particle
std::string const& Particle::getName() const {return m_name;}
unsigned int const& Particle::getAmount() const {return m_amount;}
int const& Particle::getCharge() const {return m_charge;}
float const& Particle::getSpin() const {return m_spin;}

void Particle::printInfo() const
{
    std::cout << "Particle Info:"
    <<  m_name
    << " amount: " << m_amount    
    << " Total Charge: " << m_amount * m_charge
    << " Spin: "  << m_spin << "\n";
}


// Atom
Particle const& Atom::getNeutrons() const {return m_Nucleus.getNeutrons();}
Particle const& Atom::getProtons() const {return m_Nucleus.getProtons();}
Particle const& Atom::getElectrons() const {return m_Electrons;}

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


