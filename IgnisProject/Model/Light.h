#ifndef LIGHT_H
#define LIGHT_H

#include <MagicWeapon.h>


class Light : public MagicWeapon
{
    public:
        Light();
        virtual ~Light();
        Light(const Light& other);
        Light& operator=(const Light& other);

        float strategyAccuracy(const Character& att, const Character& def)const override;


};

#endif // LIGHT_H
