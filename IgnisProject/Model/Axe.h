#ifndef AXE_H
#define AXE_H

#include <PhysycalWeapon.h>


class Axe : public PhysycalWeapon
{
    private:

    public:
        Axe();
        virtual ~Axe();
        Axe(const Axe& other);
        Axe& operator=(const Axe& other);

        float strategyAccuracy(const Character& att, const Character& def)const override;



};

#endif // AXE_H
