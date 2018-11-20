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
    this->setExp(0);
    this->setLevel(1);
}
Archer::~Archer()
{
     std::cout << "Archer Destructor" << std::endl;
}

Archer::Archer(const Archer& other):Character(other)
{
    //copy ctor
}

Archer& Archer::operator=(const Archer& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    Character::operator=(rhs);
    return *this;
}

Archer* Archer::clone()const
{
    return new Archer(*this);
}

void Archer::addHealth(){
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
void Archer::addStrength(){
    int tmp= this->getStrength();
    int ran = rand();
    while(ran>100){
        ran=rand();
    }
    if((tmp>0)&&(ran>=85)){
        tmp++;
    }
    this->setStrength(tmp);
}
void Archer::addDefense(){
    int tmp= this->getDefense();
    int ran= rand();
    while(ran>100){
        ran = rand();
    }
    if((tmp>0)&&(ran>=90)){
        tmp++;
    }
    this->setDefense(tmp);
}
void Archer::addSpeed(){
    int tmp= this->getSpeed();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    if((tmp>0)&&(ran>=85)){
        tmp++;
    }
    this->setSpeed(tmp);
}

void Archer::addResistance(){
    int tmp= this->getResistance();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    if((tmp>0)&&(ran>=95)){
        tmp++;
    }
    this->setResistance(tmp);
}
void Archer::addMagic(){
    int tmp= this->getMagic();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    if((tmp>0)&&(ran>=100)){
        tmp++;
    }
    this->setMagic(tmp);
}
void Archer::addLuck(){
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
void Archer::addSkill(){
    int tmp= this->getSkill();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    if((tmp>0)&&(ran>=70)){
        tmp++;
    }
    this->setSkill(tmp);
}

