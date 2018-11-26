#ifndef MAGE_H
#define MAGE_H

#include "Character.h"


class Mage : public Character
{
    private:
        static const WeaponType type;

    public:
        Mage(string name="XXX");
        virtual ~Mage();
        Mage(const Mage& other);
        Mage& operator=(const Mage& other);

        Mage* clone()const;

        void setWeapon(Weapon* weapon);

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

#endif // MAGE_H
