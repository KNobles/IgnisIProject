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

    this->setLevel(0);

    Weapon *weapon = new Sword();
    setWeapon(*weapon);

}

Warrior::~Warrior()
{
    std::cout << "Warrior Destructor" << std::endl;
}
/*
Warrior::Warrior(const Warrior& other):Character(const Character& other)
{
    //copy ctor
}

Warrior& Warrior::operator=(const Warrior& rhs):Character::operator=(const Character& rhs)
{i

}
*/

void Warrior::setWeapon(Weapon& weapon)
{
    if (weapon.TYPE == types[0] || weapon.TYPE == types[1])
        Character::setWeapon(weapon);
}



std::string Warrior::str()const{
    stringstream strs;
    strs << getName() << endl << "HP : " << getHealth() << endl << "STRENGTH : " << getStrength() << endl
    << "DEFENSE : " << getDefense() << endl << "SPEED : " << getSpeed() << endl << "MOVEMENT : " << getMovement() <<" EXPERIENCE :" <<getExp() <<" LEVEL :" <<getLevel()<<endl;
    return strs.str();
}
void Warrior::addExp(const int exp){
    int tmp= this->getExp();
    int cmp=0 ;
    if(exp>0)
        tmp+=exp;
    if(tmp>100){
         cmp=tmp/100;
         tmp=tmp%100;
        this->addLevel(cmp);
    }
    this->setExp(tmp);

}
void Warrior::addLevel(const int level){
    int tmp =this->getLevel();
    if(level>0){
        tmp+=level;
    }
    this->setLevel(tmp);
}
