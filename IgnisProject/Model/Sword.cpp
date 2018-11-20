#include "Sword.h"

Sword::Sword():PhysicalWeapon()
{
    //ctor
}

Sword::~Sword()
{
    //dtor
}

Sword::Sword(const Sword& other):PhysicalWeapon(other)
{
    //copy ctor
}

Sword& Sword::operator=(const Sword& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    PhysicalWeapon::operator=(rhs);
    return *this;
}

Sword* Sword::clone()const
{
    return new Sword(*this);
}

float Sword::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = PhysicalWeapon::strategyAccuracy(att, def);

    //Weapon Triangle Advantage
    if(def.getWeapon()->TYPE == WeaponType::axe)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon()->TYPE == WeaponType::lance)
        accuracy-=5;

    return accuracy;
}
