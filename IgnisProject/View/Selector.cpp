#include "Selector.h"


Selector::Selector(std::string name)
{
    if(!this->texture.loadFromFile("Assets/Sprites/Tiles/" + name))
    {
        std::cout << "FAILED TO LOAD" << std::endl;
        system("pause");
    }
    this->setTexture(this->texture);
//    this->setTextureRect(sf::IntRect(0,0, 16, 16));
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

void Selector::updatePosition()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->getPosition().y < 600-16)
    {
        this->move(0,16.f);
        cout << "x: " << this->getPosition().x/16 << " y: " << this->getPosition().y/16 << endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->getPosition().y > 0)
    {
        this->move(0,-16.f);
        cout << "x: " << this->getPosition().x/16 << " y: " << this->getPosition().y/16 << endl;    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getPosition().x < 800-16)
    {
        this->move(16.f, 0);
        cout << "x: " << this->getPosition().x/16 << " y: " << this->getPosition().y/16 << endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->getPosition().x > 0)
    {
        this->move(-16.f, 0);
        cout << "x: " << this->getPosition().x/16 << " y: " << this->getPosition().y/16 << endl;
    }
}
