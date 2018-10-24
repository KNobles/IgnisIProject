#include "Warrior.h"

Warrior::Warrior(std::string name):Character()
{
    this->setName(name);
    this->setHealth(35);
    this->setStrength(10);
    this->setDefense(4);
    this->setSpeed(4);
    this->setMovement(6);
    this->setSkill(10);
    this->setLuck(6);
    this->setMagic(0);
    this->setResistance(3);
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
{

}
*/

void Warrior::attack(Character &c)const{
    //Normalement c'est un pourcentage de l'arme, ici on a mis 85. Pour le moins, en temps normal, on ajoute l'avoid de l'arme.
    float accuracy = ((this->getSkill() * 3. + this->getLuck())/2 + 85) - ((c.getSpeed()*3 + c.getLuck())/2);

    //float critical = this->weapon.getCritical() + this->skill/2;

    int rate = rand()%100+1;

    cout << rate << endl;

    int damage = this->getStrength() - c.getDefense();
    if(damage<0)
        damage=0;

    if(rate <= accuracy)
    {
        c.setHealth(c.getHealth() - damage);
        cout << this->getName() << " dealt " << damage << endl;
    }
    else
        cout << this->getName() << " missed" << endl;
}

std::string Warrior::str()const{
    stringstream strs;
    strs << getName() << endl << "HP : " << getHealth() << endl << "STRENGTH : " << getStrength()
    << "DEFENSE : " << getDefense() << endl << "SPEED : " << getSpeed() << endl << "MOVEMENT : " << getMovement() << endl;
    return strs.str();
}
