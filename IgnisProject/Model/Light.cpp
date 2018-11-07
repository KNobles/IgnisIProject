#include "Light.h"

Light::Light():MagicWeapon()
{
    //ctor
}

Light::~Light()
{
    //dtor
}

Light::Light(const Light& other):MagicWeapon(other)
{
    //copy ctor
}

Light& Light::operator=(const Light& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    MagicWeapon::operator=(rhs);
    return *this;
}

float Light::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = MagicWeapon::strategyAccuracy(att, def);

    //Weapon Triangle Advantage
    if(def.getWeapon().TYPE == WeaponType::dark)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon().TYPE == WeaponType::anima)
        accuracy-=5;

    return accuracy;
}


