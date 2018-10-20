#ifndef WARRIOR_H
#define WARRIOR_H

#include <Character.h>


class Warrior : public Character
{
    public:
        Warrior();
        virtual ~Warrior();
        Warrior(const Warrior& other);
        Warrior& operator=(const Warrior& other);

    protected:

    private:
};

#endif // WARRIOR_H
