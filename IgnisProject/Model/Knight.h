#ifndef KNIGHT_H
#define KNIGHT_H

#include<string>
#include<sstream>
#include <Character.h>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;


class Knight : public Character
{
    private:
        static const WeaponType[] TYPES;
        Weapon weapon;

    public:
        Knight();
        virtual ~Knight();
        Knight(const Knight& other);
        Knight& operator=(const Knight& other);

        Weapon getWeapon()const;
        void set Weapon(const Weapon weapon);

        void attack(const Character& c)const override;
        string str()const override;

    protected:


};

#endif // KNIGHT_H
