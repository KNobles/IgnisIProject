#ifndef MAGICWEAPON_H
#define MAGICWEAPON_H

#include <Weapon.h>
#include "Character.h"


class MagicWeapon : public Weapon
{
    public:
        MagicWeapon(string name="DEFAULT", int damages=1, int hit=85, int range=1, int crit=0, int worth=1, int uses = 40, WeaponType type=WeaponType::light);
        virtual ~MagicWeapon();
        MagicWeapon(const MagicWeapon& other);
        MagicWeapon& operator=(const MagicWeapon& other);

        virtual MagicWeapon* clone()const=0;

        virtual float strategyAccuracy(const Character& att, const Character& def)const override;
        float strategyDamages(const Character& att, const Character& def)const override;


};

#endif // MAGICWEAPON_H
