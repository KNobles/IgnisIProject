#include "MagicWeapon.h"

MagicWeapon::MagicWeapon(string name, int damages, int hit, int range, int crit, int worth, int uses, WeaponType type):Weapon(name, damages, hit, range, crit, worth, uses, type)
{
    //ctor
}

MagicWeapon::~MagicWeapon()
{
    //dtor
}

MagicWeapon::MagicWeapon(const MagicWeapon& other):Weapon(other)
{
    //copy ctor
}

MagicWeapon& MagicWeapon::operator=(const MagicWeapon& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    Weapon::operator=(rhs);
    return *this;
}

float MagicWeapon::strategyAccuracy(const Character& att, const Character& def)const
{
    return ((float)((att.getSkill() * 3. + att.getLuck())/2 + this->getHit()) - (float)((def.getSpeed()*3 + (float)def.getLuck())/2));
}

float MagicWeapon::strategyDamages(const Character& att, const Character& def)const
{
    return att.getMagic()+this->getDamages()-def.getResistance();
}
