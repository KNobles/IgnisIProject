#include "Warrior.h"

const WeaponType Warrior::types[] = {WeaponType::sword, WeaponType::axe};

Warrior::Warrior(std::string name):Character()
{
    this->setName(name);
    this->setHealth(28);
    this->setStrength(12);
    this->setDefense(7);
    this->setSpeed(7);
    this->setMovement(6);
    this->setSkill(8);
    this->setLuck(6);
    this->setMagic(0);
    this->setResistance(3);
    this->setExp(0);
    Weapon *weapon = new Sword();
    setWeapon(*weapon);
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
{i

}
*/

void Warrior::setWeapon(Weapon& weapon)
{
    if (weapon.TYPE == types[0] || weapon.TYPE == types[1])
        Character::setWeapon(weapon);
}



std::string Warrior::str()const{
    stringstream strs;
    strs << getName() << endl << "HP : " << getHealth() << endl << "STRENGTH : " << getStrength() << endl
    << "DEFENSE : " << getDefense() << endl << "SPEED : " << getSpeed() << endl << "MOVEMENT : " << getMovement() << endl;
    return strs.str();
}
void Warrior::setExp(const int exp){
    if(this->getExp()>=100){

    }
}
