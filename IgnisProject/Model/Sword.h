#ifndef SWORD_H
#define SWORD_H

#include "Character.h"
#include <Weapon.h>


class Sword : public Weapon
{
    private:

    public:
        Sword();
        virtual ~Sword();
        Sword(const Sword& other);
        Sword& operator=(const Sword& other);

        float strategyAccuracy(const Character& att, const Character& def)const override;
        float strategyDamages(const Character& att, const Character& def)const override;


};

#endif // SWORD_H
