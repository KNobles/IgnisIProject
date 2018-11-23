#include "CharacterSprite.h"

CharacterSprite::CharacterSprite()
{

}

CharacterSprite::CharacterSprite(Character* character)
{
//    this->sprite = sprite;
    this->texture.loadFromFile("Assets/Sprites/Character/Roy/Roy-idle.png");
    this->setTexture(this->texture);
    this->character = character;
    this->setPosition(0.f, 0.f);
    this->isSelected = false;
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
    this->setIsSelected(other.getIsSelected());
}

CharacterSprite& CharacterSprite::operator=(const CharacterSprite& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

//    this->sprite = rhs.sprite;
    this->character = rhs.character;
    this->setTexture(rhs.texture);
    this->setPosition(rhs.getPosition());
    this->setIsSelected(rhs.getIsSelected());
    return *this;
}

Character* CharacterSprite::getCharacter()const
{
    return this->character;
}

bool CharacterSprite::getIsSelected()const
{
    return this->isSelected;
}

void CharacterSprite::setIsSelected(bool isSelected)
{
    this->isSelected = isSelected;
}
