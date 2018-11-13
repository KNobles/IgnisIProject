#include "Bow.h"

Bow::Bow():PhysicalWeapon()
{
    //ctor
}

Bow::~Bow()
{
    //dtor
}

Bow::Bow(const Bow& other):PhysicalWeapon(other)
{
    //copy ctor
}

Bow& Bow::operator=(const Bow& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    PhysicalWeapon::operator=(rhs);
    return *this;
}

Bow* Bow::clone()const
{
    return new Bow(*this);
}


