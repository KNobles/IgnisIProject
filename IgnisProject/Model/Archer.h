#ifndef ARCHER_H
#define ARCHER_H
#include<string>
#include<sstream>
#include<random>
#include "Character.h"
#include<iostream>
#include<thread>
#include<vector>


using std::string;
using std::stringstream;
using std::cout;
using std::endl;
using std::vector;

class Archer : public Character
{
    private:
        static const WeaponType types[];

    public:
        Archer(std::string name);
        virtual ~Archer();
        Archer(const Archer& other);
        Archer& operator=(const Archer& other);

//        void setWeapon(const Weapon weapon);

        std::string str()const override;


    protected:


};

#endif // ARCHER_H
