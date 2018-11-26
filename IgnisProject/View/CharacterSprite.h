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

    private:
        Character* character;
        sf::Texture texture;
        bool isSelected;
};

#endif // CHARACTERSPRITE_H
