#include "Warrior.h"

Warrior::Warrior():Character()
{
    this->setName("Kevin");
    this->setHealth(200);
    this->setStrength(20);
    this->setDefense(30);
    this->setSpeed(4);
    this->setMovement(6);
}

Warrior::~Warrior()
{
    std::cout << "Warrior Destructor" << std::endl;
}
/*
Warrior::Warrior(const Warrior& other):Character(const Character& other)
{
    //copy ctor
}

Warrior& Warrior::operator=(const Warrior& rhs):Character::operator=(const Character& rhs)
{

}
*/
std::string Warrior::str()const{
    stringstream strs;
    strs << getName() << endl << "HP : " << getHealth() << endl << "STRENGTH : " << getStrength()
    << "DEFENSE : " << getDefense() << endl << "SPEED : " << getSpeed() << endl << "MOVEMENT : " << getMovement() << endl;
    return strs.str();
}
