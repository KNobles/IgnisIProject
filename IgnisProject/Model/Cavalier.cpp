#include "Cavalier.h"

const WeaponType Cavalier::types[] = {WeaponType::sword, WeaponType::lance};

Cavalier::Cavalier(string name):Character()
{
    this->setName(name);
    this->setHealth(16);
    this->setStrength(4);
    this->setDefense(7);
    this->setSpeed(7);
    this->setMovement(7);
    this->setSkill(6);
    this->setLuck(0);
    this->setMagic(3);
    this->setResistance(0);
    this->setExp(0);
    this->setLevel(0);
    Sword sword;
    this->setWeapon(&sword);
}

Cavalier::~Cavalier()
{
    //dtor
}

Cavalier::Cavalier(const Cavalier& other):Character(other)
{
    this->setWeapon(other.getWeapon());
}

Cavalier& Cavalier::operator=(const Cavalier& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    Character::operator=(rhs);
    this->setWeapon(rhs.getWeapon());
    return *this;
}

void Cavalier::setWeapon(Weapon* weapon)
{
    if(weapon->TYPE == types[0] || weapon->TYPE == types[1])
        Character::setWeapon(weapon);
}

Cavalier* Cavalier::clone()const
{
    return new Cavalier(*this);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Cavalier::addHealth(){
    int tmp= this->getHealth();
    int ran=rand();
    while (ran>100){
            ran=rand();
    }
    int max;
    if(this->getName()=="David"){
        max=15;
    }
    else{
        max=55;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setHealth(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Cavalier::addStrength(){
    int tmp= this->getStrength();
    int ran = rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="David"){
        max=45;
    }
    else{
        max=80;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setStrength(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Cavalier::addDefense(){
    int tmp= this->getDefense();
    int ran= rand();
    while(ran>100){
        ran = rand();
    }
    int max;
    if(this->getName()=="David"){
        max=55;
    }
    else{
        max=90;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setDefense(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Cavalier::addSpeed(){
    int tmp= this->getSpeed();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="David"){
        max=40;
    }
    else{
        max=80;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setSpeed(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Cavalier::addResistance(){
    int tmp= this->getResistance();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="David"){
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
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Cavalier::addMagic(){
    int tmp= this->getMagic();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="David"){
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
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Cavalier::addLuck(){
    int tmp= this->getLuck();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="David"){
        max=50;
    }
    else{
        max=100;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setLuck(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Cavalier::addSkill(){
    int tmp= this->getSkill();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="David"){
        max=45;
    }
    else{
        max=80;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setSkill(tmp);
}
