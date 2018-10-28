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
}
Archer::~Archer()
{
     std::cout << "Archer Destructor" << std::endl;
}

Archer::Archer(const Archer& other)
{
    //copy ctor
}
//Weapon Archer::getWeapon()const{
//    return weapon;
//}
//void Archer::setWeapon(const Weapon weapon){
//    this->weapon=weapon;
//}
Archer& Archer::operator=(const Archer& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

//void Archer::attack(Character &c)const{
//    //Normalement c'est un pourcentage de l'arme, ici on a mis 85. Pour le moins, en temps normal, on ajoute l'avoid de l'arme.
//    float accuracy = ((float)((this->getSkill() * 3. + this->getLuck())/2 + 85) - (float)((c.getSpeed()*3 + c.getLuck())/2));
//
//    //float critical = this->weapon.getCritical() + this->skill/2;
//
//    int rate = rand()%100+1;
//
//    cout << rate << endl;
//
//    int damage = this->getStrength() - c.getDefense();
//    if(damage<0)
//        damage=0;
//
//    if(rate <= accuracy)
//    {
//        c.setHealth(c.getHealth() - damage);
//        if(c.getHealth() <=0)
//            c.die();
//        cout << this->getName() << " dealt " << damage << endl;
//    }
//    else
//        cout << this->getName() << " missed" << endl;
//}
std::string Archer::str()const{
    stringstream strs;
    strs << getName() << endl << "HP : " << getHealth() << endl << "STRENGTH : " << getStrength()
    << "DEFENSE : " << getDefense() << endl << "SPEED : " << getSpeed() << endl << "MOVEMENT : " << getMovement() << endl;
    return strs.str();
}


