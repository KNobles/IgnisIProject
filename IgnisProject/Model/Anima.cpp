#include "Anima.h"

Anima::Anima()
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
    float accuracy = ((float)((att.getSkill() * 3. + att.getLuck())/2 + this->getHit()) - (float)((def.getSpeed()*3 + (float)def.getLuck())/2));

    //Weapon Triangle Advantage
    if(def.getWeapon().TYPE == WeaponType::light)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon().TYPE == WeaponType::dark)
        accuracy-=5;

    return accuracy;
}

float Anima::strategyDamages(const Character& att, const Character& def)const
{
    return att.getMagic()+this->getDamages()-def.getResistance();
}

