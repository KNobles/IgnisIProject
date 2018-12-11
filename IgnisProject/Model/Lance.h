#ifndef LANCE_H
#define LANCE_H

#include <PhysycalWeapon.h>


class Lance : public PhysicalWeapon
{
    public:
        Lance(string name="Lance", int damages=4, int hit=85, int range=1, int crit=0, int worth=1, int uses = 40, WeaponType type=WeaponType::lance);
        virtual ~Lance();
        Lance(const Lance& other);
        Lance& operator=(const Lance& other);

        Lance* clone()const;

        float strategyAccuracy(const Character& att, const Character& def)const override;

};

#endif // LANCE_H
