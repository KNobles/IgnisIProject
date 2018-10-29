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
    this->setLevel(0);

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
    << "DEFENSE : " << getDefense() << endl << "SPEED : " << getSpeed() << endl << "MOVEMENT : " << getMovement() <<" EXPERIENCE :" <<getExp() <<" LEVEL :" <<getLevel()<<endl;
    return strs.str();
}
void Warrior::addHealth(){
    int tmp= this->getHealth();
    int ran=rand();
    while (ran>100){
        ran=rand();
    }
    if((tmp>0) && (ran>15)){
        tmp++;
    }
    this->setHealth(tmp);
}
void Warrior::addStrength(){
    int tmp= this->getStrength();
    if(tmp>0){
        tmp++;
    }
    this->setStrength(tmp);
}
void Warrior::addDefense(){
     int tmp= this->getDefense();
    if(tmp>0){
        tmp++;
    }
    this->setDefense(tmp);
}
void Warrior::addSpeed(){
     int tmp= this->getSpeed();
    if(tmp>0){
        tmp++;
    }
    this->setSpeed(tmp);
}
void Warrior::addMovement(){
     int tmp= this->getMovement();
    if(tmp>0){
        tmp++;
    }
    this->setMovement(tmp);
}
void Warrior::addResistance(){
     int tmp= this->getResistance();
    if(tmp>0){
        tmp++;
    }
    this->setResistance(tmp);
}
void Warrior::addMagic(){
     int tmp= this->getMagic();
    if(tmp>0){
        tmp++;
    }
    this->setMagic(tmp);
}
void Warrior::addLuck(){
     int tmp= this->getLuck();
    if(tmp>0){
        tmp++;
    }
    this->setLuck(tmp);
}


