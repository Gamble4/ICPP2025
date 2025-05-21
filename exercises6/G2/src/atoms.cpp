#include "atoms.hpp"
#include <iostream>


Particle const& Nucleus::getNeutrons() const
{
    return m_Neutrons;
}

Particle const& Nucleus::getProtons() const
{
    return m_Protons;
}


void Particle::printInfo() const
{
    std::cout << "name: " << m_name << " amount: " << m_amount
    << " Charge: " << m_charge << " Spin: " << m_spin << "\n";
}


void Atom::printInfo()
{
    std::cout << "name: " << m_name << " A: " << m_A << " Z: " << m_Z << "\n";
}

Particle const& Atom::getNeutrons() const
{
    return m_Nucleus.getNeutrons();
}

Particle const& Atom::getProtons() const
{
    return m_Nucleus.getProtons();
}

Particle const& Atom::getElectrons() const
{
    return m_Electrons;
}

