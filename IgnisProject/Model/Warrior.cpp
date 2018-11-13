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
    this->setLevel(1);

    Weapon *weapon = new Sword();
    setWeapon(weapon);

}

Warrior::~Warrior()
{
    std::cout << "Warrior Destructor" << std::endl;
}

Warrior::Warrior(const Warrior& other):Character(other)
{

    if(other.getWeapon()->TYPE == types[0] || other.getWeapon()->TYPE == types[0])
    {
        this->setWeapon(other.getWeapon());
    }

}

Warrior& Warrior::operator=(const Warrior& rhs)
{
    if(this==&rhs) return *this;
    Character::operator=(rhs);
    return *this;
}

bool Warrior::operator==(const Warrior* w)const
{
    cout << "bonjour" << endl;
    return Character::operator==(w);
}


Warrior* Warrior::clone()const
{
    return new Warrior(*this);
}


void Warrior::setWeapon(Weapon* weapon)
{
    if (weapon->TYPE == types[0] || weapon->TYPE == types[1])
        Character::setWeapon(weapon);
}

std::string Warrior::str()const{
    stringstream strs;
    strs << getName() << endl << "HP : " << getHealth() << endl << "STRENGTH : " << getStrength() << endl
    << "DEFENSE : " << getDefense() << endl << "SPEED : " << getSpeed() << endl << "MOVEMENT : " << getMovement()<< endl << "SKILL : " << getSkill()<< endl <<"RESISTANCE : "<<getResistance()
    << endl <<"MAGIC : "<<getMagic()<< endl <<"LUCK : "<<getLuck()<< endl <<"EXPERIENCE : " <<getExp()<< endl  <<"LEVEL : " <<getLevel()<<endl;
    return strs.str();
}
void Warrior::addHealth(){
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
void Warrior::addStrength(){
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
void Warrior::addDefense(){
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
void Warrior::addSpeed(){
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
void Warrior::addMovement(){
    int tmp= this->getMovement();
    int ran=rand();
    while (ran>100){
        ran = rand();
    }
    if((tmp>0)&&(ran>=80)){
        tmp++;
    }
    this->setMovement(tmp);
}
void Warrior::addResistance(){
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
void Warrior::addMagic(){
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
void Warrior::addLuck(){
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
void Warrior::addSkill(){
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

