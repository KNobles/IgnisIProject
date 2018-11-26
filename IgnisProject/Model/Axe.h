#ifndef AXE_H
#define AXE_H

#include <PhysycalWeapon.h>


class Axe : public PhysicalWeapon
{
    private:

    public:
        Axe();
        virtual ~Axe();
        Axe(const Axe& other);
        Axe& operator=(const Axe& other);

        Axe* clone()const;
        float strategyAccuracy(const Character& att, const Character& def)const override;



};

#endif // AXE_H
