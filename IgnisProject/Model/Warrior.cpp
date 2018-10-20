#include "Warrior.h"

Warrior::Warrior()
{
    //ctor
}

Warrior::~Warrior()
{
    //dtor
}

Warrior::Warrior(const Warrior& other)
{
    //copy ctor
}

Warrior& Warrior::operator=(const Warrior& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
