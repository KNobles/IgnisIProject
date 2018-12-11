#include "Character.h"

int Character::increment=1000;

Character::Character()
{
    charId = new int(increment++);
    dead=false;
}

Character::~Character()
{
    cout << "Character Destructor" << endl;
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
    this->resistance = other.resistance;
    this->luck = other.luck;
    this->skill = other.skill;
    this->magic = other.magic;
    this->charId = new int(*other.charId);
    this->exp=other.exp;
    this->level=other.level;
    this->dead=other.dead;
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
    this->exp=rhs.exp;
    this->level=rhs.exp;
    this->dead=rhs.dead;
    delete charId;
    this->charId = new int(*rhs.charId);
    return *this;
}

bool Character::operator==(const Character* c)const{
    if(this->name == c->name)
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

int Character::getExp()const{
    return exp;
}

int Character::getLevel()const{
    return level;
}

string Character::getName()const{
    return name;
}

Weapon* Character::getWeapon()const
{
    return weapon;
}
//methode pour recuperer l'etat du character
bool Character::isDead()const
{
    return dead;
}

void Character::setName(const string name){
    this->name = name;
}

void Character::setHealth(const int health){
    if(health>=0)
        this->health = health;
    else
        this->health=0;
}

void Character::setDefense(const int defense){
    if(defense>=0)
        this->defense = defense;
}

void Character::setSkill(const int skill){
    if(skill>=0)
        this->skill = skill;
}

void Character::setResistance(const int resistance)
{
    if(resistance>=0)
        this->resistance = resistance;
}

void Character::setMagic(const int magic)
{
    if(magic>=0)
        this->magic = magic;
}

void Character::setLuck(const int luck)
{
    if(luck>=0)
        this->luck = luck;
}

void Character::setMovement(const int movement){
    if(movement>=0)
        this->movement = movement;
}

void Character::setSpeed(const int speed){
    if(speed>=0)
        this->speed = speed;
}

void Character::setExp(const int exp){
    if(exp>=0)
        this->exp = exp;
}

void Character::setLevel(const int level){
    if(level>=0)
        this->level=level;
}

void Character::setStrength(const int strength){
    if(strength>0)
        this->strength = strength;
}

void Character::setWeapon(Weapon* weapon)
{
        this->weapon = weapon->clone();
}
//methode pour definir l'etat du character a "mort"
void Character::die()
{
    dead=true;
}
//methode qui permet a un character d'attaqué
void Character::attack(Character& c)const{
    //Accuracy = chances to hit from this - chances to avoid from c
    float accuracy = this->getWeapon()->strategyAccuracy(*this, c);
    float critical = this->getWeapon()->getCrit() + this->getSkill()/2;
    int rate = rand()%100+1;
    cout << rate << endl;
    int damage = this->getWeapon()->strategyDamages(*this, c);
    if(damage<0)
        damage=0;
    if(rate <= critical)
    {
        c.setHealth(c.getHealth() - damage*3);
        cout << this->getName() << " dealt " << damage << endl;
    }
    else if (rate <= accuracy)
    {
        c.setHealth(c.getHealth() - damage);
        cout << this->getName() << " dealt " << damage << endl;
    }
    else
        cout << this->getName() << " missed" << endl;
}
//Methode qui permet a 2 character de combattre
void combat(Character& c1, Character& c2, int dist){
    int diff = c1.getSpeed() - c2.getSpeed();

    if(c2.getWeapon()->getRange() == dist)
    {
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
        c1.addExp(c1.calculatorExp(c2));
        c2.addExp(c2.calculatorExp(c1));
    }
    else{
        if(diff >= 5){
            c1.attack(c2);
            c1.attack(c2);
        }
        else {
            c1.attack(c2);
        }
        c1.addExp(c1.calculatorExp(c2));
    }
}
//Methode qui va additionner l'experience du character a l'experience qu'il vient de gagner apres un combat
void Character::addExp(const int exp){
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
//Methode qui va determiner par calcul l'experience gagner a la fin du combat.
int Character::calculatorExp(Character& c){
    int LD =c.getLevel()-this->getLevel();
    int exp=0;
    if(this->getHealth()>0){
        if(c.getHealth()>0){
            exp= (31+LD)/3;
            return exp;
        }
        else{
            exp=20+(LD*3);
            return exp;
        }
    }
    return exp;
}
//Methode qui va ajouter un niveau au character et faire appel au methode d'ajout sur toutes les caractéristiques
void Character::addLevel(const int level){
      int tmpBefore =this->getLevel();
      int tmpAfter =this->getLevel();
    if(level>0){
        tmpAfter+=level;
    }
    this->setLevel(tmpAfter);
    for (int i=tmpBefore;i<=tmpAfter-1;i++){
        this->addHealth();
        this->addStrength();
        this->addDefense();
        this->addSpeed();
        this->addResistance();
        this->addMagic();
        this->addLuck();
        this->addSkill();
    }
}
string Character::str()const
{
    stringstream strs;
    strs << getName() << endl << "HP : " << getHealth() << endl << "STRENGTH : " << getStrength() << endl
    << "DEFENSE : " << getDefense() << endl << "SPEED : " << getSpeed() << endl << "MOVEMENT : " << getMovement()<< endl << "SKILL : " << getSkill()<< endl <<"RESISTANCE : "<<getResistance()
    << endl <<"MAGIC : "<<getMagic()<< endl <<"LUCK : "<<getLuck()<< endl <<"EXPERIENCE : " <<getExp()<< endl  <<"LEVEL : " <<getLevel()<<endl;
    return strs.str();

}

