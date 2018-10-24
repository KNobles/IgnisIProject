#ifndef WEAPON_H
#define WEAPON_H

#include<iostream>
#include<string>
#include<sstream>

using std::string;
using std::stringstream;
using std::endl;

enum WeaponType {sword, axe, lance, bow, anima, light, dark, staff};


class Weapon
{
    private:
        int *id;
        static int increment;

        string name;
        int hit;
        int range;
        int crit;
        int worth;

    protected:


    public:
        const WeaponType TYPE;
        Weapon(string name="DEFAULT", int hit=1, int range=1, int crit=0, int worth=1, WeaponType type=sword);
        virtual ~Weapon();
        Weapon(const Weapon& other);
        Weapon& operator=(const Weapon& other);

        bool operator==(const Weapon& w)const;

        int getId()const;
        string getName()const;
        int getHit()const;
        int getRange()const;
        int getCrit()const;
        int getWorth()const;

        void setName(const string name);
        void setHit(const int hit);
        void setRange(const int range);
        void setCrit(const int crit);
        void setWorth(const int worth);

        string str()const;

};

#endif // WEAPON_H
