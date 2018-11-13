#ifndef MAGICWEAPON_H
#define MAGICWEAPON_H

#include <Weapon.h>
#include "Character.h"


class MagicWeapon : public Weapon
{
    public:
        MagicWeapon();
        virtual ~MagicWeapon();
        MagicWeapon(const MagicWeapon& other);
        MagicWeapon& operator=(const MagicWeapon& other);

        virtual MagicWeapon* clone()const=0;

        virtual float strategyAccuracy(const Character& att, const Character& def)const override;
        float strategyDamages(const Character& att, const Character& def)const override;


};

#endif // MAGICWEAPON_H
