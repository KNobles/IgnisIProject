#include "Knight.h"


const WeaponType Knight::types = {WeaponType::lance};

Knight::Knight(std::string name):Character()
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
    this->setLevel(1);
}

Knight::~Knight()
{
    //dtor
}

Knight::Knight(const Knight& other):Character(other)
{
            this->setWeapon(other.getWeapon());
}

void Knight::setWeapon(Weapon* weapon)
{
    if (weapon->TYPE == types)
        Character::setWeapon(weapon);
}
Knight* Knight::clone()const
{
    return new Knight(*this);
}
Knight& Knight::operator=(const Knight& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

std::string Knight::str()const{
    stringstream strs;
    strs << getName() << endl << "HP : " << getHealth() << endl << "STRENGTH : " << getStrength() << endl
    << "DEFENSE : " << getDefense() << endl << "SPEED : " << getSpeed() << endl << "MOVEMENT : " << getMovement()<< endl << "SKILL : " << getSkill()<< endl <<"RESISTANCE : "<<getResistance()
    << endl <<"MAGIC : "<<getMagic()<< endl <<"LUCK : "<<getLuck()<< endl <<"EXPERIENCE : " <<getExp()<< endl  <<"LEVEL : " <<getLevel()<<endl;
    return strs.str();
}
void Knight::addHealth(){
    int tmp= this->getHealth();
    int ran=rand();
    while (ran>100){
            ran=rand();
    }
    if((tmp>0) && (ran>=55)){
        tmp++;
    }
    this->setHealth(tmp);
}
void Knight::addStrength(){
    int tmp= this->getStrength();
    int ran = rand();
    while(ran>100){
        ran=rand();
    }
    if((tmp>0)&&(ran>=75)){
        tmp++;
    }
    this->setStrength(tmp);
}
void Knight::addDefense(){
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
void Knight::addSpeed(){
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
void Knight::addResistance(){
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
void Knight::addMagic(){
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
void Knight::addLuck(){
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
void Knight::addSkill(){
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
