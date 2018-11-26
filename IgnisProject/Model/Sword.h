#ifndef SWORD_H
#define SWORD_H

#include <PhysycalWeapon.h>


class Sword : public PhysicalWeapon
{
    private:

    public:
        Sword();
        virtual ~Sword();
        Sword(const Sword& other);
        Sword& operator=(const Sword& other);

        Sword* clone()const;

        float strategyAccuracy(const Character& att, const Character& def)const override;


};

#endif // SWORD_H
