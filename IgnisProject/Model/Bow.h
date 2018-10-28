#ifndef BOW_H
#define BOW_H

#include <Weapon.h>
#include "Character.h"


class Bow : public Weapon
{
    public:
        Bow();
        virtual ~Bow();
        Bow(const Bow& other);
        Bow& operator=(const Bow& other);

        float strategyAccuracy(const Character& att, const Character& def)const override;
        float strategyDamages(const Character& att, const Character& def)const override;

};

#endif // BOW_H
