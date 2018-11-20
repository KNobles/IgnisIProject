#include "CharacterSprite.h"

CharacterSprite::CharacterSprite(Character* character)
{
//    this->sprite = sprite;
    this->character = character;
}

CharacterSprite::~CharacterSprite()
{

}

CharacterSprite::CharacterSprite(const CharacterSprite& other)
{
//    this->sprite = other.sprite;
    this->character = other.character;
}

CharacterSprite& CharacterSprite::operator=(const CharacterSprite& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

//    this->sprite = rhs.sprite;
    this->character = rhs.character;
    return *this;
}
