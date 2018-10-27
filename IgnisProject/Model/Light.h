#ifndef LIGHT_H
#define LIGHT_H

#include <Weapon.h>
#include "Character.h"


class Light : public Weapon
{
    public:
        Light();
        virtual ~Light();
        Light(const Light& other);
        Light& operator=(const Light& other);

        float strategyAccuracy(const Character& att, const Character& def)const override;
        float strategyDamages(const Character& att, const Character& def)const override;


};

#endif // LIGHT_H
