#include "Weapon.h"

int Weapon::increment = 1000;

Weapon::Weapon(string name, int damages, int hit, int range, int crit, int worth, int uses, WeaponType type):TYPE(type)
{
    id = new int(increment++);
    this->name = name;
    this->damages = damages;
    this->hit = hit;
    this->range = range;
    this->crit = crit;
    this->worth = worth;
    this->uses = uses;
}

Weapon::~Weapon()
{
    delete id;
}

Weapon::Weapon(const Weapon& other):TYPE(other.TYPE)
{
    this->name = other.name;
    this->damages = other.damages;
    this->hit = other.hit;
    this->range = other.range;
    this->crit = other.crit;
    this->worth = other.worth;
    this->uses = other.uses;
    this->id = new int(*other.id);
}

Weapon& Weapon::operator=(const Weapon& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    this->name = rhs.name;
    this->damages = rhs.damages;
    this->hit = rhs.hit;
    this->range = rhs.range;
    this->crit = rhs.crit;
    this->worth = rhs.worth;
    this->uses = rhs.uses;
    delete id;
    this->id = new int(*rhs.id);
    //assignment operator
    return *this;
}

bool Weapon::operator==(const Weapon& w)const
{
    if(this->name == w.name)
        return true;
    return false;
}

int Weapon::getId()const
{
    return *id;
}

string Weapon::getName()const
{
    return name;
}

int Weapon::getDamages()const
{
    return damages;
}

int Weapon::getHit()const
{
    return hit;
}

int Weapon::getRange()const
{
    return range;
}

int Weapon::getCrit()const
{
    return crit;
}

int Weapon::getWorth()const
{
    return worth;
}

int Weapon::getDurability()const
{
    return uses;
}

void Weapon::setName(const string name)
{
    this->name = name;
}

void Weapon::setHit(const int hit)
{
    if(hit>=0)
        this->hit = hit;
}

void Weapon::setRange(const int range)
{
    if(range>0)
        this->range = range;
}

void Weapon::setCrit(const int crit)
{
    if(crit>=0)
        this->crit = crit;
}

void Weapon::setWorth(const int worth)
{
    if(worth>0)
        this->worth = worth;
}

void Weapon::setDurability(const int uses)
{
    if(uses >= 0)
        this->uses = uses;
}
//Methode qui gere la durabilité de l'arme
void Weapon::decrement()
{
    this->uses--;
}

string Weapon::str()const
{
    stringstream strs;
    strs << name << endl << "HIT : " << hit << endl << "RANGE : " << range << endl << "CRIT : " << crit << endl << "WORTH : " << worth << endl;
    return strs.str();
}
