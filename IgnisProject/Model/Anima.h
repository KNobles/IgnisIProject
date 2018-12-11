#ifndef ANIMA_H
#define ANIMA_H

#include <MagicWeapon.h>

class Anima : public MagicWeapon
{
    public:
        Anima(string name="Anima", int damages=4, int hit=85, int range=2, int crit=0, int worth=1, int uses = 40, WeaponType type=WeaponType::anima);
        virtual ~Anima();
        Anima(const Anima& other);
        Anima& operator=(const Anima& other);

        virtual Anima* clone()const;
        float strategyAccuracy(const Character& att, const Character& def)const override;

};

#endif // ANIMA_H
