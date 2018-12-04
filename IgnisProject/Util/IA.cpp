#include "IA.h"

IA::IA(GameDataRef data)
{
    this->data = data;
}

IA::~IA()
{
    //dtor
}

IA::IA(const IA& other)
{
    //copy ctor
}

IA& IA::operator=(const IA& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
void IA::moveIA(){
}
void IA::attackIA(){
}
void IA::chooseTargetIA(){
}
