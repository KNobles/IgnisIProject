#ifndef AXE_H
#define AXE_H

#include <PhysycalWeapon.h>


class Axe : public PhysicalWeapon
{
    private:

    public:
        Axe(string name="Axe", int damages=5, int hit=85, int range=1, int crit=0, int worth=1, int uses = 35, WeaponType type=WeaponType::axe);
        virtual ~Axe();
        Axe(const Axe& other);
        Axe& operator=(const Axe& other);

        Axe* clone()const;
        float strategyAccuracy(const Character& att, const Character& def)const override;



};

#endif // AXE_H
