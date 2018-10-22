#include "Cursor.h"


Cursor::Cursor(float radius, sf::Color color)
{
    this->setRadius(radius);
    this->setFillColor(color);
}

Cursor::~Cursor()
{
    //dtor
}

void Cursor::setMovement()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->getPosition().y+16 < 512)
    {
        this->move(0,16.f);
        cout << "x: " << this->getPosition().x << " y: " << this->getPosition().y << endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->getPosition().y > 0)
    {
        this->move(0,-16.f);
        cout << "x: " << this->getPosition().x << " y: " << this->getPosition().y << endl;    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getPosition().x+16 < 512)
    {
        this->move(16.f, 0);
        cout << "x: " << this->getPosition().x << " y: " << this->getPosition().y << endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->getPosition().x > 0)
    {
        this->move(-16.f, 0);
        cout << "x: " << this->getPosition().x << " y: " << this->getPosition().y << endl;
    }
}
