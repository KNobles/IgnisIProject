#include "Archer.h"

Archer::Archer()
{
    //ctor
}

Archer::~Archer()
{
    //dtor
}

Archer::Archer(const Archer& other)
{
    //copy ctor
}

Archer& Archer::operator=(const Archer& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
