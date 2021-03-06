#include "CharacterSprite.h"

//CharacterSprite::CharacterSprite()
//{
//
//}

CharacterSprite::CharacterSprite(Character* character, std::string file)
{
//    this->sprite = sprite;
    setTextureFromFile(file);
    this->character = character;
    this->setPosition(0.f, 0.f);
    this->isDone = false;
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

bool CharacterSprite::getIsDone()const
{
    return this->isDone;
}

int CharacterSprite::sumPositions()const
{
    return getPosition().x + getPosition().y;
}

void CharacterSprite::setIsDone(bool isDone)
{
    this->isDone = isDone;
}

void CharacterSprite::setIsSelected(bool isSelected)
{
    this->isSelected = isSelected;
}

bool CharacterSprite::operator==(const CharacterSprite& other)const
{
    return this->character == other.character;
}

void CharacterSprite::setTextureFromFile(std::string file)
{
    this->texture.loadFromFile("Assets/Sprites/Character/" + file);
    this->setTexture(texture);
}
