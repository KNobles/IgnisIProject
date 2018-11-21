#ifndef CHARACTERSPRITE_H
#define CHARACTERSPRITE_H
#include <SFML/Graphics.hpp>
#include "Character.h"

class CharacterSprite : sf::Sprite
{
    public:
        CharacterSprite();
        CharacterSprite(Character*);
        virtual ~CharacterSprite();
        CharacterSprite(const CharacterSprite& other);
        CharacterSprite& operator=(const CharacterSprite& other);

    private:
        sf::Texture texture;
        Character* character;
};

#endif // CHARACTERSPRITE_H
