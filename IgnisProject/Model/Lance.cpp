#include "Lance.h"

Lance::Lance():PhysycalWeapon()
{
    //ctor
}

Lance::~Lance()
{
    //dtor
}

Lance::Lance(const Lance& other)
{
    //copy ctor
}

Lance& Lance::operator=(const Lance& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

float Lance::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = PhysycalWeapon::strategyAccuracy(att, def);

    //Weapon Triangle Advantage
    if(def.getWeapon().TYPE == WeaponType::sword)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon().TYPE == WeaponType::axe)
        accuracy-=5;

    return accuracy;
}
