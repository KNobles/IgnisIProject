#ifndef CHARACTER_H
#define CHARACTER_H
#include<string>
#include<sstream>
#include<iostream>
#include "Weapon.h"
#include "Team.h"

using std::string;
using std::cout;
using std::stringstream;
using std::endl;

class Character
{
    private:
        int *charId;
        string name;
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
        int level;
        static int increment;
        Weapon* weapon;

    public:
        Character();
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        bool operator==(const Character* c)const;

        int getHealth()const;
        int getStrength()const;
        int getDefense()const;
        int getSpeed()const;
        int getMovement()const;
        int getSkill()const;
        int getResistance()const;
        int getMagic()const;
        int getLuck()const;
        string getName()const;
        int* getCharId()const;
        int getExp()const;
        int getLevel()const;

        Weapon* getWeapon()const;


        void setHealth(const int health);
        void setStrength(const int strenth);
        void setDefense(const int defense);
        void setSpeed(const int speed);
        void setName(const string name);
        void setCharId(const int* id);
        void setMovement(const int movement);
        void setSkill(const int skill);
        void setResistance(const int resistance);
        void setMagic(const int magic);
        void setLuck(const int luck);
        void setExp(const int exp);
        void setLevel(const int level);
        void setWeapon(Weapon *weapon);

        virtual Character* clone()const = 0;


        void die();
        void attack(Character& c)const;
        virtual string str()const;
        friend void combat(Character& c1, Character& c2);
        void addExp(const int exp);
        void addLevel(const int level);
        int calculatorExp(Character& c);
        virtual void addHealth()=0;
        virtual void addStrength()=0;
        virtual void addDefense()=0;
        virtual void addSpeed()=0;
        virtual void addResistance()=0;
        virtual void addMagic()=0;
        virtual void addLuck()=0;
        virtual void addSkill()=0;

};

#endif // CHARACTER_H
