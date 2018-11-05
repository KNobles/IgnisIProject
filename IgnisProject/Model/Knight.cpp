#include "Knight.h"

const WeaponType Knight::TYPES {WeaponType::lance};

Knight::Knight():Character()
{
    setHealth(18);
    setStrength(8);
    setSkill(4);
    setSpeed(2);
    setDefense(11);
    setMovement(4);
    setResistance(0);
    setMagic(0);
    setLuck(5);
}

Knight::~Knight()
{
    //dtor
}

Knight::Knight(const Knight& other)
{
    this->setHealth(other.getHealth());
    this->setStrength(other.getStrength());
    this->setSkill(other.getSkill());
    this->setDefense(other.getDefense());
    this->setCharId(other.getCharId());
    this->setResistance(other.getResistance());
    this->setMagic(other.getMagic());
    this->setLuck(other.getLuck());
}

Knight& Knight::operator=(const Knight& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
