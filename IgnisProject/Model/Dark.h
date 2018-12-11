#ifndef DARK_H
#define DARK_H

#include <MagicWeapon.h>


class Dark : public MagicWeapon
{
    public:
        Dark(string name="Dark", int damages=3, int hit=95, int range=2, int crit=0, int worth=1, int uses = 40, WeaponType type=sword);
        virtual ~Dark();
        Dark(const Dark& other);
        Dark& operator=(const Dark& other);

        Dark* clone()const;

        float strategyAccuracy(const Character& att, const Character& def)const override;

};

#endif // DARK_H
