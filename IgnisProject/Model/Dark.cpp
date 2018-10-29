#include "Dark.h"

Dark::Dark():MagicWeapon()
{
    //ctor
}

Dark::~Dark()
{
    //dtor
}

Dark::Dark(const Dark& other)
{
    //copy ctor
}

Dark& Dark::operator=(const Dark& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

float Dark::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = MagicWeapon::strategyAccuracy(att, def);

    //Weapon Triangle Advantage
    if(def.getWeapon().TYPE == WeaponType::anima)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon().TYPE == WeaponType::light)
        accuracy-=5;

    return accuracy;
}
