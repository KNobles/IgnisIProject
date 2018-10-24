#include "Character.h"

int Character::increment=1000;

Character::Character()
{
    charId = new int(increment++);
}

Character::~Character()
{
    std::cout << "Character Destructor" << std::endl;
    delete charId;
}

Character::Character(const Character& other)
{
    this->name = other.name;
    this->health = other.health;
    this->strength = other.strength;
    this->defense = other.defense;
    this->speed = other.speed;
    this->movement = other.movement;
    this->charId = new int(*other.charId);
}

Character& Character::operator=(const Character& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    this->name = rhs.name;
    this->health = rhs.health;
    this->strength = rhs.strength;
    this->defense = rhs.defense;
    this->speed = rhs.speed;
    this->movement = rhs.movement;
    delete charId;
    this->charId = new int(*rhs.charId);
    return *this;
}

bool Character::operator==(const Character& c)const{
    if(charId == c.getCharId())
        return true;
    return false;
}

int* Character::getCharId()const{
    return charId;
}

int Character::getHealth()const{
    return health;
}

int Character::getDefense()const{
    return defense;
}

int Character::getSkill()const{
    return skill;
}

int Character::getResistance()const{
    return resistance;
}

int Character::getMagic()const{
    return magic;
}

int Character::getLuck()const{
    return luck;
}

int Character::getMovement()const{
    return movement;
}

int Character::getSpeed()const{
    return speed;
}

int Character::getStrength()const{
    return strength;
}

std::string Character::getName()const{
    return name;
}

void Character::setName(const std::string name){
    this->name = name;
}

void Character::setHealth(const int health){
    if(health>0)
        this->health = health;
}

void Character::setDefense(const int defense){
    if(defense>0)
        this->defense = defense;
}

void Character::setSkill(const int skill){
    if(skill>0)
        this->skill = skill;
}

void Character::setResistance(const int resistance)
{
    if(resistance>0)
        this->resistance = resistance;
}

void Character::setMagic(const int magic)
{
    if(magic>0)
        this->magic = magic;
}

void Character::setLuck(const int luck)
{
    if(luck>0)
        this->luck = luck;
}

void Character::setMovement(const int movement){
    if(movement>0)
        this->movement = movement;
}

void Character::setSpeed(const int speed){
    if(speed>0)
        this->speed = speed;
}

void Character::die()
{
    delete this;
}

void Character::setStrength(const int strength){
    if(strength>0)
        this->strength = strength;
}

void Character::attack(Character& c)const{
}

void combat(Character& c1, Character& c2){
    int diff = c1.getSpeed() - c2.getSpeed();
    if(diff >= 5){
        c1.attack(c2);
        c2.attack(c1);
        c1.attack(c2);
    }
    else if(diff <= -5 ){
        c1.attack(c2);
        c2.attack(c1);
        c2.attack(c1);
    }
    else{
        c1.attack(c2);
        c2.attack(c1);
    }
}
