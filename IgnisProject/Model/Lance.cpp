#include "Lance.h"

Lance::Lance(string name, int damages, int hit, int range, int crit, int worth, int uses, WeaponType type):PhysicalWeapon(name, damages, hit, range, crit, worth, uses , type)
{
    //ctor
}

Lance::~Lance()
{
    //dtor
}

Lance::Lance(const Lance& other):PhysicalWeapon(other)
{
    //copy ctor
}

Lance& Lance::operator=(const Lance& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    PhysicalWeapon::operator=(rhs);
    return *this;
}

Lance* Lance::clone()const
{
    return new Lance(*this);
}

float Lance::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = PhysicalWeapon::strategyAccuracy(att, def);

    //Weapon Triangle Advantage
    if(def.getWeapon()->TYPE == WeaponType::sword)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon()->TYPE == WeaponType::axe)
        accuracy-=5;

    return accuracy;
}
