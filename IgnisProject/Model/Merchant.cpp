#include "Merchant.h"

Merchant::Merchant()
{
    //ctor
}

Merchant::~Merchant()
{
    //dtor
}

Merchant::Merchant(const Merchant& other)
{
    for(unsigned int i=0; i < other.merchandises.size(); i++)
    {
        add(other.merchandises[i]);
    }
}

Merchant& Merchant::operator=(const Merchant& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    for(unsigned int i=0; i < merchandises.size(); i++)
    {
        merchandises.pop_back();
    }
    merchandises.clear();

    for(unsigned int i=0; i < rhs.merchandises.size(); i++)
    {
        merchandises.push_back(rhs.merchandises[i]);
    }
    return *this;
}

void Merchant::add(Weapon* w)
{
    for(unsigned int i=0; i < merchandises.size(); i++)
    {
        if(w == merchandises[i])
        {
            return;
        }
    }
    merchandises.push_back(w);
}

void Merchant::remove(Weapon* w)
{
    for(unsigned int i=0; i< merchandises.size(); i++)
    {
        if(w == merchandises[i])
        {
            merchandises.erase(merchandises.begin()+i);
            return;
        }
    }
}

string Merchant::str()const
{
    stringstream result;
    for(unsigned int i=0 ; i < merchandises.size(); i++)
    {
        result << merchandises[i]->getName() << " " << merchandises[i]->getWorth() << endl;
    }
    return result.str();
}


