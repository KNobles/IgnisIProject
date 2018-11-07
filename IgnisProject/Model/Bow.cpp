#include "Bow.h"

Bow::Bow():PhysycalWeapon()
{
    //ctor
}

Bow::~Bow()
{
    //dtor
}

Bow::Bow(const Bow& other):PhysycalWeapon(other)
{
    //copy ctor
}

Bow& Bow::operator=(const Bow& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    PhysycalWeapon::operator=(rhs);
    return *this;
}


