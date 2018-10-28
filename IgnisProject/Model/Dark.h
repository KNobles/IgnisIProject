#ifndef DARK_H
#define DARK_H

#include <Weapon.h>
#include "Character.h"


class Dark : public Weapon
{
    public:
        Dark();
        virtual ~Dark();
        Dark(const Dark& other);
        Dark& operator=(const Dark& other);

        float strategyAccuracy(const Character& att, const Character& def)const override;
        float strategyDamages(const Character& att, const Character& def)const override;

};

#endif // DARK_H
