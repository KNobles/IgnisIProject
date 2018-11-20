#include "PhysycalWeapon.h"

PhysicalWeapon::PhysicalWeapon():Weapon()
{
    //ctor
}

PhysicalWeapon::~PhysicalWeapon()
{
    //dtor
}

PhysicalWeapon::PhysicalWeapon(const PhysicalWeapon& other):Weapon(other)
{
    //copy ctor
}

PhysicalWeapon& PhysicalWeapon::operator=(const PhysicalWeapon& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    Weapon::operator=(rhs);
    return *this;
}

PhysicalWeapon* PhysicalWeapon::clone()const
{
    return new PhysicalWeapon(*this);
}

float PhysicalWeapon::strategyAccuracy(const Character& att, const Character& def)const
{
    return ((float)((att.getSkill() * 3. + att.getLuck())/2 + this->getHit()) - (float)((def.getSpeed()*3 + (float)def.getLuck())/2));
}

float PhysicalWeapon::strategyDamages(const Character& att, const Character& def)const
{
    return att.getStrength()+this->getDamages()-def.getDefense();
}
