#ifndef CHARACTERSPRITE_H
#define CHARACTERSPRITE_H
#include <SFML/Graphics.hpp>
#include "Character.h"

class CharacterSprite : public sf::Sprite
{
    public:
        CharacterSprite();
        CharacterSprite(Character*);
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
