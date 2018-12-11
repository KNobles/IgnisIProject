#include "Mage.h"

const WeaponType Mage::type = WeaponType::dark;

Mage::Mage(string name):Character()
{
    setHealth(16);
    setStrength(0);
    setMagic(3);
    setSkill(1);
    setSpeed(3);
    setLuck(0);
    setDefense(2);
    setResistance(3);
    setMovement(6);
    setName(name);
    setExp(0);
    setLevel(1);
    Dark dark;
    this->setWeapon(&dark);
}

Mage::~Mage()
{
    //dtor
}

Mage::Mage(const Mage& other):Character(other)
{
    setWeapon(other.getWeapon());
}

Mage& Mage::operator=(const Mage& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    Character::operator=(rhs);
    setWeapon(rhs.getWeapon());
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
    int max;
    if(this->getName()=="Luana"){
        max=70;
    }
    else{
        max=95;
    }
    if((tmp>=0) && (ran>=max)){
        tmp++;
    }
    this->setHealth(tmp);
}

void Mage::addStrength(){
    int tmp= this->getStrength();

    int ran= rand();
    while(ran>100){
        ran = rand();
    }
    int max;
    if(this->getName()=="Luana"){
        max=80;
    }
    else{
        max=90;
    }
    if((tmp>=0) && (ran>=max)){
        tmp++;
    }
    this->setStrength(tmp);
}

void Mage::addDefense(){
    int tmp= this->getDefense();
    int ran= rand();
    while(ran>100){
        ran = rand();
    }
    int max;
    if(this->getName()=="Luana"){
        max=80;
    }
    else{
        max=90;
    }
    if((tmp>=0) && (ran>=max)){
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
    int max;
    if(this->getName()=="Luana"){
        max=50;
    }
    else{
        max=85;
    }
    if((tmp>=0) && (ran>=max)){
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
    int max;
    if(this->getName()=="Luana"){
        max=80;
    }
    else{
        max=85;
    }
    if((tmp>=0) && (ran>=max)){
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
    int max;
    if(this->getName()=="Luana"){
        max=35;
    }
    else{
        max=55;
    }
    if((tmp>=0) && (ran>=max)){
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
    int max;
    if(this->getName()=="Luana"){
        max=75;
    }
    else{
        max=90;
    }
    if((tmp>=0) && (ran>=max)){
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
    int max;
    if(this->getName()=="Luana"){
        max=55;
    }
    else{
        max=75;
    }
    if((tmp>=0) && (ran>=max)){
        tmp++;
    }
    this->setSkill(tmp);
}
