#ifndef PHYSYCALWEAPON_H
#define PHYSYCALWEAPON_H

#include <Weapon.h>
#include "Character.h"


class PhysycalWeapon : public Weapon
{
    public:
        PhysycalWeapon();
        virtual ~PhysycalWeapon();
        PhysycalWeapon(const PhysycalWeapon& other);
        PhysycalWeapon& operator=(const PhysycalWeapon& other);

        virtual float strategyAccuracy(const Character& att, const Character& def)const override;
        float strategyDamages(const Character& att, const Character& def)const override;

    protected:

    private:
};

#endif // PHYSYCALWEAPON_H
