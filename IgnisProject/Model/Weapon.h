#ifndef WEAPON_H
#define WEAPON_H

#include<iostream>
#include<string>
#include<sstream>

using std::string;
using std::stringstream;
using std::endl;

enum WeaponType {sword, axe, lance, bow, anima, light, dark, staff};

class Character;
class Weapon
{
    private:
        int *id;
        static int increment;

        string name;
        int damages;
        int hit;
        int range;
        int crit;
        int worth;
        int uses;

    protected:


    public:
        const WeaponType TYPE;
        Weapon(string name="DEFAULT", int damages=1, int hit=85, int range=1, int crit=0, int worth=1, int uses = 40, WeaponType type=sword);
        virtual ~Weapon();
        Weapon(const Weapon& other);
        Weapon& operator=(const Weapon& other);

        bool operator==(const Weapon& w)const;

        int getId()const;
        string getName()const;
        int getDamages()const;
        int getHit()const;
        int getRange()const;
        int getCrit()const;
        int getWorth()const;
        int getDurability()const;

        void setName(const string name);
        void setHit(const int hit);
        void setRange(const int range);
        void setCrit(const int crit);
        void setWorth(const int worth);
        void setDurability(const int uses);

        virtual Weapon* clone()const=0;

        void decrement();

        virtual float strategyAccuracy(const Character& att, const Character& def)const=0;
        virtual float strategyDamages(const Character& att, const Character& def)const=0;

        string str()const;

};

#endif // WEAPON_H
