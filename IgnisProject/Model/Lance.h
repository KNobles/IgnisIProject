#ifndef LANCE_H
#define LANCE_H

#include <PhysycalWeapon.h>


class Lance : public PhysycalWeapon
{
    public:
        Lance();
        virtual ~Lance();
        Lance(const Lance& other);
        Lance& operator=(const Lance& other);

        float strategyAccuracy(const Character& att, const Character& def)const override;

};

#endif // LANCE_H
