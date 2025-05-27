#ifndef H_ATOMS
#define  H_ATOMS
#include <string>
#include <vector>


class Particle
{
private:
    std::string m_name;
    unsigned int m_amount;
    int m_charge;
    float m_spin;

public:
    Particle(std::string name, unsigned int amount, int charge, float spin);

    std::string const& getName() const;
    unsigned int const& getAmount() const;
    int const& getCharge() const;
    float const& getSpin() const;
    
    void printInfo() const;

    ~Particle(){};
};

class Nucleus
{
private:
    Particle m_Neutrons; // composition
    Particle m_Protons;  // composition

public:
    Nucleus(unsigned int A, unsigned int Z);

    Particle const& getNeutrons() const;
    Particle const& getProtons() const;

    void printInfo() const;

    ~Nucleus() {};
};

class Atom
{
private:
    std::string m_name;
    unsigned int m_A;
    unsigned int m_Z;
    Nucleus m_Nucleus;    // composition
    Particle m_Electrons; // composition
    
public:    
    Atom(std::string name, unsigned int A, unsigned int Z);    

    std::string const& getName() const;
    Particle const& getNeutrons() const;
    Particle const& getProtons() const;
    Particle const& getElectrons() const;
    Nucleus const& getNucleus() const;
    
    void printInfo() const;

    ~Atom(){};
};

class Molecule
{
private:
    std::string m_name;
    std::vector<Atom> m_vAtoms; // composition
    unsigned int m_A;
    int m_charge;

public:
    Molecule(std::string name, std::vector<Atom>& vAtom);
    Molecule(std::string name, std::vector<Atom>&& vAtom);

    std::string const& getName() const;
    int const& getCharge() const;

    Atom const* begin() const;
    Atom const* end() const;
        
    void printInfo() const;

};

#endif