#ifndef ANIMA_H
#define ANIMA_H

#include <MagicWeapon.h>

class Anima : public MagicWeapon
{
    public:
        Anima();
        virtual ~Anima();
        Anima(const Anima& other);
        Anima& operator=(const Anima& other);

        virtual Anima* clone()const;
        float strategyAccuracy(const Character& att, const Character& def)const override;

};

#endif // ANIMA_H
