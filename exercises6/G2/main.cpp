#include "src/atoms.hpp"

int main()
{
    Atom Fe{"Fe", 55, 26};
    Fe.getNeutrons().printInfo();
}