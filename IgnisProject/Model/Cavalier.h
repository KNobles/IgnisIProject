#ifndef CAVALIER_H
#define CAVALIER_H

#include "Character.h"
#include "Sword.h"
#include "Lance.h"

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

class Cavalier : public Character
{
    private:
        static const WeaponType types[];


    public:
        Cavalier(string name = "xxx");
        virtual ~Cavalier();
        Cavalier(const Cavalier& other);
        Cavalier& operator=(const Cavalier& other);

        Cavalier* clone()const override;

        void setWeapon(Weapon* weapon);
        void addHealth();
        void addStrength();
        void addDefense();
        void addSpeed();
        void addResistance();
        void addMagic();
        void addLuck();
        void addSkill();


};

#endif // CAVALIER_H
