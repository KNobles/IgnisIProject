#include "Dark.h"

Dark::Dark()
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
    float accuracy = ((float)((att.getSkill() * 3. + att.getLuck())/2 + this->getHit()) - (float)((def.getSpeed()*3 + (float)def.getLuck())/2));

    //Weapon Triangle Advantage
    if(def.getWeapon().TYPE == WeaponType::anima)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon().TYPE == WeaponType::light)
        accuracy-=5;

    return accuracy;
}

float Dark::strategyDamages(const Character& att, const Character& def)const
{
    return att.getMagic()+this->getDamages()-def.getResistance();
}
