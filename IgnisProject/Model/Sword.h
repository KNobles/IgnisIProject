#ifndef SWORD_H
#define SWORD_H

#include <PhysycalWeapon.h>


class Sword : public PhysicalWeapon
{
    private:

    public:
        Sword(string name="DEFAULT", int damages=3, int hit=100, int range=1, int crit=0, int worth=1, int uses = 40, WeaponType type= WeaponType::sword);
        virtual ~Sword();
        Sword(const Sword& other);
        Sword& operator=(const Sword& other);

        Sword* clone()const;

        float strategyAccuracy(const Character& att, const Character& def)const override;


};

#endif // SWORD_H
