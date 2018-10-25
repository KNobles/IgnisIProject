#ifndef CHARACTER_H
#define CHARACTER_H
#include<string>
#include<sstream>
#include<iostream>
#include "Weapon.h"

class Character
{
    private:
        int *charId;
        std::string name;
        int health;
        int strength;
        int magic;
        int skill;
        int resistance;
        int luck;
        int defense;
        int speed;
        int movement;
        int exp;
        static int increment;

    public:
        Character();
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        bool operator==(const Character& c)const;

        int getHealth()const;
        int getStrength()const;
        int getDefense()const;
        int getSpeed()const;
        int getMovement()const;
        int getSkill()const;
        int getResistance()const;
        int getMagic()const;
        int getLuck()const;
        std::string getName()const;
        int* getCharId()const;
        int getExp()const;

        void setHealth(const int health);
        void setStrength(const int strenth);
        void setDefense(const int defense);
        void setSpeed(const int speed);
        void setName(const std::string name);
        void setCharId(const int* id);
        void setMovement(const int movement);
        void setSkill(const int skill);
        void setResistance(const int resistance);
        void setMagic(const int magic);
        void setLuck(const int luck);
        void setExp(const int exp);

        void die();
        virtual void attack(Character& c)const;
        virtual std::string str()const=0;     //Fonction virtuelle pure qui rend la classe abstraite.
        friend void combat(Character& c1, Character& c2);

};

#endif // CHARACTER_H
