#ifndef WARRIOR_H
#define WARRIOR_H
#include<string>
#include<sstream>
#include "Character.h"

using namespace std;


class Warrior : public Character
{
    public:
        Warrior();
        virtual ~Warrior();
        Warrior(const Warrior& other);
        Warrior& operator=(const Warrior& other);
        std::string str()const override;    //Redéfinition de la fonction virtuelle de Character

    protected:

    private:
};

#endif // WARRIOR_H
