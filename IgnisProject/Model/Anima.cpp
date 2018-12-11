#include "Anima.h"

Anima::Anima(string name, int damages, int hit, int range, int crit, int worth, int uses, WeaponType type):MagicWeapon(name, damages, hit, range, crit, worth, uses, type)
{
    //ctor
}

Anima::~Anima()
{
    //dtor
}

Anima::Anima(const Anima& other):MagicWeapon(other)
{
    //copy ctor
}

Anima& Anima::operator=(const Anima& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    MagicWeapon::operator=(rhs);
    return *this;
}

Anima* Anima::clone()const
{
    return new Anima(*this);
}

float Anima::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = MagicWeapon::strategyAccuracy(att, def);

    //Weapon Triangle Advantage
    if(def.getWeapon()->TYPE == WeaponType::light)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon()->TYPE == WeaponType::dark)
        accuracy-=5;

    return accuracy;
}

