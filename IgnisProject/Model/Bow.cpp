#include "Bow.h"

Bow::Bow():PhysycalWeapon()
{
    //ctor
}

Bow::~Bow()
{
    //dtor
}

Bow::Bow(const Bow& other)
{
    //copy ctor
}

Bow& Bow::operator=(const Bow& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


