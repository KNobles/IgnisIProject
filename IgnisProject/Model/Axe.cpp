#include "Axe.h"

Axe::Axe():PhysicalWeapon()
{
    //ctor
}

Axe::~Axe()
{
    //dtor
}

Axe::Axe(const Axe& other):PhysicalWeapon(other)
{
    //copy ctor
}

Axe& Axe::operator=(const Axe& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    PhysicalWeapon::operator=(rhs);
    return *this;
}

Axe* Axe::clone()const
{
    return new Axe(*this);
}

float Axe::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = PhysicalWeapon::strategyAccuracy(att, def);

    //Weapon Triangle Advantage
    if(def.getWeapon()->TYPE == WeaponType::lance)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon()->TYPE == WeaponType::sword)
        accuracy-=5;

    return accuracy;
}


