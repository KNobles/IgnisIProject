#include "Lance.h"

Lance::Lance()
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
    float accuracy = ((float)((att.getSkill() * 3. + att.getLuck())/2 + this->getHit()) - (float)((def.getSpeed()*3 + (float)def.getLuck())/2));

    //Weapon Triangle Advantage
    if(def.getWeapon().TYPE == WeaponType::sword)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon().TYPE == WeaponType::axe)
        accuracy-=5;

    return accuracy;
}

float Lance::strategyDamages(const Character& att, const Character& def)const
{
    return att.getStrength()+this->getDamages()-def.getDefense();
}
