#ifndef LANCE_H
#define LANCE_H

#include <PhysycalWeapon.h>


class Lance : public PhysicalWeapon
{
    public:
        Lance();
        virtual ~Lance();
        Lance(const Lance& other);
        Lance& operator=(const Lance& other);

        Lance* clone()const;

        float strategyAccuracy(const Character& att, const Character& def)const override;

};

#endif // LANCE_H
