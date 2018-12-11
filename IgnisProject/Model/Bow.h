#ifndef BOW_H
#define BOW_H

#include <PhysycalWeapon.h>



class Bow : public PhysicalWeapon
{
    public:
        Bow(string name="Bow", int damages=3, int hit=85, int range=2, int crit=0, int worth=1, int uses = 40, WeaponType type=WeaponType::bow);
        virtual ~Bow();
        Bow(const Bow& other);
        Bow& operator=(const Bow& other);

        Bow* clone()const;


};

#endif // BOW_H
