#include "Selector.h"


Selector::Selector(std::string name)
{
    if(!this->texture.loadFromFile("Assets/Sprites/Tiles/" + name))
    {
        std::cout << "FAILED TO LOAD" << std::endl;
        system("pause");
    }
    this->setOrigin(4,4);
    this->setTexture(this->texture);
}

sf::Texture& Selector::getTexture()
{
    return this->texture;
}

Selector::~Selector()
{
    //dtor
}

Selector& Selector::operator=(const Selector& rhs)
{
    if(this == &rhs) return *this;

    this->texture = rhs.texture;
    return *this;
}

Selector::Selector(const Selector& cursor)
{
        this->texture = cursor.texture;

}
