#ifndef BOW_H
#define BOW_H

#include <PhysycalWeapon.h>



class Bow : public PhysycalWeapon
{
    public:
        Bow();
        virtual ~Bow();
        Bow(const Bow& other);
        Bow& operator=(const Bow& other);


};

#endif // BOW_H
