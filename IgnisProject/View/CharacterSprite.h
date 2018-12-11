#ifndef CHARACTERSPRITE_H
#define CHARACTERSPRITE_H
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Warrior.h"

class CharacterSprite : public sf::Sprite
{
    public:
        CharacterSprite(Character* character = new Warrior("Maga"));
        virtual ~CharacterSprite();
        CharacterSprite(const CharacterSprite& other);
        CharacterSprite& operator=(const CharacterSprite& other);
        Character* getCharacter() const;

        bool getIsSelected()const;
        void setIsSelected(bool);
        bool getIsDone()const;
        void setIsDone(bool);
        int sumPositions()const;

        bool operator==(const CharacterSprite& other)const;

    private:
        Character* character;
        sf::Texture texture;
        bool isSelected;
        bool isDone;
};

#endif // CHARACTERSPRITE_H
