#include "PhysycalWeapon.h"

PhysycalWeapon::PhysycalWeapon():Weapon()
{
    //ctor
}

PhysycalWeapon::~PhysycalWeapon()
{
    //dtor
}

PhysycalWeapon::PhysycalWeapon(const PhysycalWeapon& other):Weapon(other)
{
    //copy ctor
}

PhysycalWeapon& PhysycalWeapon::operator=(const PhysycalWeapon& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    Weapon::operator=(rhs);
    return *this;
}

float PhysycalWeapon::strategyAccuracy(const Character& att, const Character& def)const
{
    return ((float)((att.getSkill() * 3. + att.getLuck())/2 + this->getHit()) - (float)((def.getSpeed()*3 + (float)def.getLuck())/2));
}

float PhysycalWeapon::strategyDamages(const Character& att, const Character& def)const
{
    return att.getStrength()+this->getDamages()-def.getDefense();
}
