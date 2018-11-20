#include "Mage.h"

const WeaponType Mage::type = WeaponType::dark;

Mage::Mage(string name):Character()
{
    setName(name);
}

Mage::~Mage()
{
    //dtor
}

Mage::Mage(const Mage& other):Character(other)
{
    //copy ctor
}

Mage& Mage::operator=(const Mage& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    Character::operator=(rhs);
    return *this;
}

void Mage::setWeapon(Weapon* weapon)
{
    if(weapon->TYPE == type)
    {
        Character::setWeapon(weapon);
    }
}

Mage* Mage::clone()const
{
    return new Mage(*this);
}

void Mage::addHealth(){
    int tmp= this->getHealth();
    int ran=rand();
    while (ran>100){
            ran=rand();
    }
    if((tmp>0) && (ran>=65)){
        tmp++;
    }
    this->setHealth(tmp);
}

void Mage::addStrength(){
}

void Mage::addDefense(){
    int tmp= this->getDefense();
    int ran= rand();
    while(ran>100){
        ran = rand();
    }
    if((tmp>0)&&(ran>=95)){
        tmp++;
    }
    this->setDefense(tmp);
}

void Mage::addSpeed(){
    int tmp= this->getSpeed();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    if((tmp>0)&&(ran>=80)){
        tmp++;
    }
    this->setSpeed(tmp);
}

void Mage::addResistance(){
    int tmp= this->getResistance();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    if((tmp>0)&&(ran>=90)){
        tmp++;
    }
    this->setResistance(tmp);
}

void Mage::addMagic(){
    int tmp= this->getMagic();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    if((tmp>0)&&(ran>=80)){
        tmp++;
    }
    this->setMagic(tmp);
}

void Mage::addLuck(){
    int tmp= this->getLuck();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    if((tmp>0)&&(ran>=100)){
        tmp++;
    }
    this->setLuck(tmp);
}

void Mage::addSkill(){
    int tmp= this->getSkill();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    if((tmp>0)&&(ran>=80)){
        tmp++;
    }
    this->setSkill(tmp);
}
