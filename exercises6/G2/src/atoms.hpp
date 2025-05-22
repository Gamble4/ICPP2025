#ifndef H_ATOMS
#define  H_ATOMS
#include <string>


class Particle
{
    std::string m_name;
    unsigned int m_amount;
    int m_charge;
    float m_spin;

public:
    Particle(std::string name, unsigned int amount, int charge, float spin) :
    m_name{name}, m_amount{amount}, m_charge{charge}, m_spin{spin}
    {};

    std::string const& getName() const;
    unsigned int const& getAmount() const;
    int const& getCharge() const;
    float const& getSpin() const;
    
    void printInfo() const;

    ~Particle(){};
};

class Nucleus
{
    Particle m_Neutrons;
    Particle m_Protons;

public:
    Nucleus(unsigned int A, unsigned int Z):
    m_Neutrons{Particle("Neutrons", A-Z,  0, 1)},
    m_Protons {Particle("Protons", Z, 1, 1)}    
    {};

    Particle const& getNeutrons() const;
    Particle const& getProtons() const;

    void printInfo() const;

    ~Nucleus(){};
};

class Atom
{
private:
    std::string m_name;
    unsigned int m_A;
    unsigned int m_Z;
    Nucleus m_Nucleus;
    Particle m_Electrons;
    
public:
    Atom(std::string name, unsigned int A, unsigned int Z)
    : m_name{name}, m_A{A}, m_Z{Z},     
    m_Nucleus(Nucleus(A, Z)),
    m_Electrons(Particle("Electrons", Z,  -1, 1))
    {};

    Particle const& getNeutrons() const;
    Particle const& getProtons() const;
    Particle const& getElectrons() const;
    
    void printInfo() const;

    ~Atom(){};
};

#endif