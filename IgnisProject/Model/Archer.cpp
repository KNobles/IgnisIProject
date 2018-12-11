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
    Bow bow;
    this->setWeapon(&bow);
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
    int max;
    if(this->getName()=="Alex"){
        max=75;
    }
    else{
        max=80;
    }
    if((tmp>0) && (ran>=max)){
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
    int max;
    if(this->getName()=="Alex"){
        max=65;
    }
    else{
        max=60;
    }
    if((tmp>0) && (ran>=max)){
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
    int max;
    if(this->getName()=="Alex"){
        max=60;
    }
    else{
        max=80;
    }
    if((tmp>0) && (ran>=max)){
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
    int max;
    if(this->getName()=="Alex"){
        max=25;
    }
    else{
        max=40;
    }
    if((tmp>0) && (ran>=max)){
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
    int max;
    if(this->getName()=="Alex"){
        max=85;
    }
    else{
        max=95;
    }
    if((tmp>0) && (ran>=max)){
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
   int max;
    if(this->getName()=="Alex"){
        max=90;
    }
    else{
        max=100;
    }
    if((tmp>0) && (ran>=max)){
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
    int max;
    if(this->getName()=="Alex"){
        max=75;
    }
    else{
        max=80;
    }
    if((tmp>0) && (ran>=max)){
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
    int max;
    if(this->getName()=="Alex"){
        max=55;
    }
    else{
        max=90;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setSkill(tmp);
}

