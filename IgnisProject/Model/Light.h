#ifndef LIGHT_H
#define LIGHT_H

#include <MagicWeapon.h>


class Light : public MagicWeapon
{
    public:
        Light(string name="Light", int damages=5, int hit=75, int range=2, int crit=2, int worth=1, int uses = 40, WeaponType type=WeaponType::light);
        virtual ~Light();
        Light(const Light& other);
        Light& operator=(const Light& other);

        Light* clone()const;

        float strategyAccuracy(const Character& att, const Character& def)const override;


};

#endif // LIGHT_H
