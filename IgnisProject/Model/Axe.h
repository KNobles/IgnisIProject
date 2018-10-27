#ifndef AXE_H
#define AXE_H

#include <Weapon.h>
#include "Character.h"


class Axe : public Weapon
{
    private:

    public:
        Axe();
        virtual ~Axe();
        Axe(const Axe& other);
        Axe& operator=(const Axe& other);

        float strategyAccuracy(const Character& att, const Character& def)const override;
        float strategyDamages(const Character& att, const Character& def)const override;



};

#endif // AXE_H
