#include "Light.h"

Light::Light()
{
    //ctor
}

Light::~Light()
{
    //dtor
}

Light::Light(const Light& other)
{
    //copy ctor
}

Light& Light::operator=(const Light& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

float Light::strategyAccuracy(const Character& att, const Character& def)const
{
    //basic formula
    float accuracy = ((float)((att.getSkill() * 3. + att.getLuck())/2 + this->getHit()) - (float)((def.getSpeed()*3 + (float)def.getLuck())/2));

    //Weapon Triangle Advantage
    if(def.getWeapon().TYPE == WeaponType::dark)
        accuracy+=5;

    //Weapon Triangle Disadvantage
    else if(def.getWeapon().TYPE == WeaponType::anima)
        accuracy-=5;

    return accuracy;
}

float Light::strategyDamages(const Character& att, const Character& def)const
{
    return att.getMagic()+this->getDamages()-def.getResistance();
}
