#ifndef WARRIOR_H
#define WARRIOR_H
#include<string>
#include<sstream>
#include<random>
#include "Character.h"
#include<iostream>
#include<thread>


using namespace std;


class Warrior : public Character
{
    public:
        Warrior(std::string name);
        virtual ~Warrior();
        Warrior(const Warrior& other);
        Warrior& operator=(const Warrior& other);

        void attack(Character& c)const override;
        std::string str()const override;    //Redéfinition de la fonction virtuelle de Character

    protected:

    private:
};

#endif // WARRIOR_H
