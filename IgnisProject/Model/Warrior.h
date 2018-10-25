#ifndef WARRIOR_H
#define WARRIOR_H
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


class Warrior : public Character
{
    private:
        static const WeaponType types[];
        Weapon weapon;


    public:
        Warrior(std::string name);
        virtual ~Warrior();
        Warrior(const Warrior& other);
        Warrior& operator=(const Warrior& other);

        Weapon getWeapon()const;
        void setWeapon(const Weapon weapon);


        void attack(Character& c)const override;
        std::string str()const override;    //Redéfinition de la fonction virtuelle de Character

    protected:
};

#endif // WARRIOR_H
