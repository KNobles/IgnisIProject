#include "Axe.h"

Axe::Axe()
{
    //ctor
}

Axe::~Axe()
{
    //dtor
}

Axe::Axe(const Axe& other)
{
    //copy ctor
}

Axe& Axe::operator=(const Axe& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

float Axe::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = ((float)((att.getSkill() * 3. + att.getLuck())/2 + this->getHit()) - (float)((def.getSpeed()*3 + (float)def.getLuck())/2));

    //Weapon Triangle Advantage
    if(def.getWeapon().TYPE == WeaponType::lance)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon().TYPE == WeaponType::sword)
        accuracy-=5;

    return accuracy;
}

float Axe::strategyDamages(const Character& att, const Character& def)const
{
    return att.getStrength()+this->getDamages()-def.getDefense();
}

