#ifndef MERCHANT_H
#define MERCHANT_H

#include <vector>
#include <sstream>
#include "Weapon.h"


using std::vector;
using std::string;
using std::stringstream;

class Merchant
{
    private:
        vector<Weapon*> merchandises;

    public:
        Merchant();
        virtual ~Merchant();
        Merchant(const Merchant& other);
        Merchant& operator=(const Merchant& other);

        void add(Weapon* w);
        void remove(Weapon* w);

        string str()const;


    protected:


};

#endif // MERCHANT_H
