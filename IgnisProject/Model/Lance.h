#ifndef LANCE_H
#define LANCE_H

#include <Weapon.h>
#include "Character.h"


class Lance : public Weapon
{
    public:
        Lance();
        virtual ~Lance();
        Lance(const Lance& other);
        Lance& operator=(const Lance& other);

        float strategyAccuracy(const Character& att, const Character& def)const override;
        float strategyDamages(const Character& att, const Character& def)const override;

};

#endif // LANCE_H
