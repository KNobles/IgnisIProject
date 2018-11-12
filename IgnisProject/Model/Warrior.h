#ifndef WARRIOR_H
#define WARRIOR_H
#include<string>
#include<sstream>
#include<random>
#include "Character.h"
#include<iostream>
#include<thread>
#include<vector>
#include "Sword.h"


using std::string;
using std::stringstream;
using std::cout;
using std::endl;
using std::vector;


class Warrior : public Character
{
    private:
        static const WeaponType types[];


    public:
        Warrior(string name);
        virtual ~Warrior();
        Warrior(const Warrior& other);
        Warrior& operator=(const Warrior& other);

        void setWeapon(Weapon& weapon);
        std::string str()const override;    //Redéfinition de la fonction virtuelle de Character
        void addHealth();
        void addStrength();
        void addDefense();
        void addSpeed();
        void addMovement();
        void addResistance();
        void addMagic();
        void addLuck();
        void addSkill();


    protected:
};

#endif // WARRIOR_H
