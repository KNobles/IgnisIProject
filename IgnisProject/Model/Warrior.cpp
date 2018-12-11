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
        this->setWeapon(other.getWeapon());
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
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Warrior::addHealth(){
    int tmp= this->getHealth();
    int ran=rand();
    while (ran>100){
            ran=rand();
    }
    int max;
    if(this->getName()=="Kevin"){
        max=55;
    }
    else{
        max=65;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setHealth(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Warrior::addStrength(){
    int tmp= this->getStrength();
    int ran = rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="Kevin"){
        max=45;
    }
    else{
        max=35;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setStrength(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Warrior::addDefense(){
    int tmp= this->getDefense();
    int ran= rand();
    while(ran>100){
        ran = rand();
    }
    int max;
    if(this->getName()=="Kevin"){
        max=65;
    }
    else{
        max=75;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setDefense(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Warrior::addSpeed(){
    int tmp= this->getSpeed();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="Kevin"){
        max=85;
    }
    else{
        max=95;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setSpeed(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Warrior::addResistance(){
    int tmp= this->getResistance();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="Kevin"){
        max=75;
    }
    else{
        max=70;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setResistance(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Warrior::addMagic(){
    int tmp= this->getMagic();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="Kevin"){
        max=95;
    }
    else{
        max=90;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setMagic(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Warrior::addLuck(){
    int tmp= this->getLuck();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="Kevin"){
        max=85;
    }
    else{
        max=90;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setLuck(tmp);
}
//Methode qui ajoute un point de caracteristique selon un random et qui le compare une variable qui determine la chance d'obtenir un point en plus
void Warrior::addSkill(){
    int tmp= this->getSkill();
    int ran=rand();
    while(ran>100){
        ran=rand();
    }
    int max;
    if(this->getName()=="Kevin"){
        max=75;
    }
    else{
        max=80;
    }
    if((tmp>0) && (ran>=max)){
        tmp++;
    }
    this->setSkill(tmp);
}

