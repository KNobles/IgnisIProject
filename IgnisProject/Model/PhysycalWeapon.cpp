#include "PhysycalWeapon.h"

PhysicalWeapon::PhysicalWeapon(string name, int damages, int hit, int range, int crit, int worth, int uses, WeaponType type):Weapon(name, damages, hit, range, crit, worth, uses, type)
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
