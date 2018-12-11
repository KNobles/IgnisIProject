#include "Light.h"

Light::Light(string name, int damages, int hit, int range, int crit, int worth, int uses, WeaponType type):MagicWeapon(name, damages, hit, range, crit, worth, uses, type)
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

Light* Light::clone()const
{
    return new Light(*this);
}

float Light::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = MagicWeapon::strategyAccuracy(att, def);

    //Weapon Triangle Advantage
    if(def.getWeapon()->TYPE == WeaponType::dark)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon()->TYPE == WeaponType::anima)
        accuracy-=5;

    return accuracy;
}


