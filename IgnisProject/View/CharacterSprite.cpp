#include "CharacterSprite.h"

CharacterSprite::CharacterSprite()
{

}

CharacterSprite::CharacterSprite(Character* character)
{
//    this->sprite = sprite;
    this->texture.loadFromFile("Assets/Sprites/Character/Roy/Roy-idle");
    this->setTexture(this->texture);
    this->character = character;
    this->setPosition(0.f, 0.f);
}

CharacterSprite::~CharacterSprite()
{

}

CharacterSprite::CharacterSprite(const CharacterSprite& other)
{
//    this->sprite = other.sprite;
    this->setTexture(other.texture);
    this->character = other.character;
    this->setPosition(other.getPosition());
}

CharacterSprite& CharacterSprite::operator=(const CharacterSprite& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

//    this->sprite = rhs.sprite;
    this->character = rhs.character;
    this->setTexture(rhs.texture);
    this->setPosition(rhs.getPosition());
    return *this;
}
