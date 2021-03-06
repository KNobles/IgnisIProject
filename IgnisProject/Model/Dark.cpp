#include "Dark.h"

Dark::Dark(string name, int damages, int hit, int range, int crit, int worth, int uses, WeaponType type):MagicWeapon(name, damages, hit, range, crit, worth, uses, type)
{
    //ctor
}

Dark::~Dark()
{
    //dtor
}

Dark::Dark(const Dark& other):MagicWeapon(other)
{
    //copy ctor
}

Dark& Dark::operator=(const Dark& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    MagicWeapon::operator=(rhs);
    return *this;
}

Dark* Dark::clone()const
{
    return new Dark(*this);
}
//Methode qui determine la chance que possede le premiere caractere de toucher le second
float Dark::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = MagicWeapon::strategyAccuracy(att, def);

    //Weapon Triangle Advantage
    if(def.getWeapon()->TYPE == WeaponType::anima)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon()->TYPE == WeaponType::light)
        accuracy-=5;

    return accuracy;
}
