#include "Bow.h"

Bow::Bow(string name, int damages, int hit, int range, int crit, int worth, int uses, WeaponType type):PhysicalWeapon(name, damages, hit, range, crit, worth, uses, type)
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


