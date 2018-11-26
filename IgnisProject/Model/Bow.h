#ifndef BOW_H
#define BOW_H

#include <PhysycalWeapon.h>



class Bow : public PhysicalWeapon
{
    public:
        Bow();
        virtual ~Bow();
        Bow(const Bow& other);
        Bow& operator=(const Bow& other);

        Bow* clone()const;


};

#endif // BOW_H
