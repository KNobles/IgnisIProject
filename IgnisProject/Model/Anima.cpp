#include "Anima.h"

Anima::Anima():MagicWeapon()
{
    //ctor
}

Anima::~Anima()
{
    //dtor
}

Anima::Anima(const Anima& other)
{
    //copy ctor
}

Anima& Anima::operator=(const Anima& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

float Anima::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = MagicWeapon::strategyAccuracy(att, def);

    //Weapon Triangle Advantage
    if(def.getWeapon().TYPE == WeaponType::light)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon().TYPE == WeaponType::dark)
        accuracy-=5;

    return accuracy;
}

