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

void Character::setMovement(const int movement){
    if(movement>0)
        this->movement = movement;
}

void Character::setSpeed(const int speed){
    if(speed>0)
        this->speed = speed;
}

void Character::setStrength(const int strength){
    if(strength>0)
        this->strength = strength;
}


