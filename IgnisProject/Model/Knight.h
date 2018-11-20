#ifndef KNIGHT_H
#define KNIGHT_H

#include<string>
#include<sstream>
#include <Character.h>
#include<string>
#include<sstream>
#include<random>
#include "Character.h"
#include<iostream>
#include<thread>
#include<vector>
#include "Lance.h"


using std::string;
using std::stringstream;
using std::cout;
using std::endl;


class Knight : public Character
{
    private:
        static const WeaponType types;
    public:
        Knight(string name);
        virtual ~Knight();
        Knight(const Knight& other);
        Knight& operator=(const Knight& other);
        void setWeapon(Weapon *weapon);
        Knight* clone()const override;
        string str()const override;
        void addHealth();
        void addStrength();
        void addDefense();
        void addSpeed();
        void addResistance();
        void addMagic();
        void addLuck();
        void addSkill();

    protected:


};

#endif // KNIGHT_H
