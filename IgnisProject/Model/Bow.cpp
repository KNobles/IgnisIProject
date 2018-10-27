#include "Bow.h"

Bow::Bow()
{
    //ctor
}

Bow::~Bow()
{
    //dtor
}

Bow::Bow(const Bow& other)
{
    //copy ctor
}

Bow& Bow::operator=(const Bow& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

float Bow::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = ((float)((att.getSkill() * 3. + att.getLuck())/2 + this->getHit()) - (float)((def.getSpeed()*3 + (float)def.getLuck())/2));

    return accuracy;
}

float Bow::strategyDamages(const Character& att, const Character& def)const
{
    return att.getStrength()+this->getDamages()-def.getDefense();
}
