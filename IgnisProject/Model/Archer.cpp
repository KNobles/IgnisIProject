#include "Archer.h"

const WeaponType Archer::types[] = {WeaponType::bow};

Archer::Archer(std::string name):Character ()
{
    this->setName(name);
    this->setHealth(16);
    this->setStrength(5);
    this->setDefense(5);
    this->setSpeed(6);
    this->setMovement(5);
    this->setSkill(8);
    this->setLuck(7);
    this->setMagic(0);
    this->setResistance(0);
}
Archer::~Archer()
{
     std::cout << "Archer Destructor" << std::endl;
}

Archer::Archer(const Archer& other)
{
    //copy ctor
}
Archer& Archer::operator=(const Archer& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

std::string Archer::str()const{
    stringstream strs;
    strs << getName() << endl << "HP : " << getHealth() << endl << "STRENGTH : " << getStrength()
    << "DEFENSE : " << getDefense() << endl << "SPEED : " << getSpeed() << endl << "MOVEMENT : " << getMovement() << endl;
    return strs.str();
}


