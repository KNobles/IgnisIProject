#ifndef ANIMA_H
#define ANIMA_H

#include <Weapon.h>
#include "Character.h"

class Anima : public Weapon
{
    public:
        Anima();
        virtual ~Anima();
        Anima(const Anima& other);
        Anima& operator=(const Anima& other);

        float strategyAccuracy(const Character& att, const Character& def)const override;
        float strategyDamages(const Character& att, const Character& def)const override;

};

#endif // ANIMA_H
