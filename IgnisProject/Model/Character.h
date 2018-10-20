#ifndef CHARACTER_H
#define CHARACTER_H
#include<string>
#include<sstream>


class Character
{
    private:
        int *charId;
        std::string name;
        int health;
        int strength;
        int defense;
        int speed;
        int movement;

        static int increment;

    public:
        Character();
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        bool operator==(const Character& c)const;


        int getHealth()const;
        int getStrength()const;
        int getDefense()const;
        int getSpeed()const;
        int getMovement()const;
        std::string getName()const;
        int getCharId()const;


        void setHealth(const int health);
        void setStrength(const int strenth);
        void setDefense(const int defense);
        void setSpeed(const int speed);
        void setName(const std::string name);
        void setCharId(const int* id);
        void setMovement(const int movement);

        virtual void str()const = 0;     //Fonction virtuelle pure qui rend la classe abstraite.





};

#endif // CHARACTER_H
