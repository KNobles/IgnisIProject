#ifndef DARK_H
#define DARK_H

#include <MagicWeapon.h>


class Dark : public MagicWeapon
{
    public:
        Dark();
        virtual ~Dark();
        Dark(const Dark& other);
        Dark& operator=(const Dark& other);

        Dark* clone()const;

        float strategyAccuracy(const Character& att, const Character& def)const override;

};

#endif // DARK_H
