#ifndef PHYSYCALWEAPON_H
#define PHYSYCALWEAPON_H

#include <Weapon.h>
#include "Character.h"


class PhysicalWeapon : public Weapon
{
    public:
        PhysicalWeapon(string name="DEFAULT", int damages=1, int hit=85, int range=1, int crit=0, int worth=1, int uses = 40, WeaponType type=WeaponType::sword);
        virtual ~PhysicalWeapon();
        PhysicalWeapon(const PhysicalWeapon& other);
        PhysicalWeapon& operator=(const PhysicalWeapon& other);

        virtual PhysicalWeapon* clone()const;

        virtual float strategyAccuracy(const Character& att, const Character& def)const override;
        float strategyDamages(const Character& att, const Character& def)const override;

    protected:

    private:
};

#endif // PHYSYCALWEAPON_H
