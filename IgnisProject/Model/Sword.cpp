#include "Sword.h"

Sword::Sword():Weapon()
{
    //ctor
}

Sword::~Sword()
{
    //dtor
}

Sword::Sword(const Sword& other)
{
    //copy ctor
}

Sword& Sword::operator=(const Sword& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

float Sword::strategyAccuracy(const Character& att, const Character& def)const
{
    return ((float)((att.getSkill() * 3. + att.getLuck())/2 + this->getHit()) - (float)((def.getSpeed()*3 + def.getLuck())/2));
}

float Sword::strategyDamages(const Character& att, const Character& def)const
{
    return att.getStrength()+this->getDamages()-def.getDefense();
}
