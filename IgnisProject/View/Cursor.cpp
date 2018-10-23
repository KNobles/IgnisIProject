#include "Cursor.h"


Cursor::Cursor()
{
    this->setFillColor(sf::Color::Transparent);
    this->setOutlineThickness(1.f);
    this->setOutlineColor(sf::Color::Blue);
    this->setSize(sf::Vector2f(16.f, 16.f));
}

Cursor::Cursor(float size, float thickness, sf::Color color)
{
    this->setFillColor(sf::Color::Transparent);
    this->setOutlineThickness(1.f);
    this->setOutlineColor(color);
    this->setSize(sf::Vector2f(size, size));
}

Cursor::~Cursor()
{
    //dtor
}

Cursor& Cursor::operator=(const Cursor& rhs)
{
    if(this == &rhs) return *this;

    this->setFillColor(rhs.getFillColor());
    this->setOutlineColor(rhs.getOutlineColor());
    this->setOutlineThickness(rhs.getOutlineThickness());
    this->setSize(rhs.getSize());
    return *this;
}

Cursor::Cursor(const Cursor& cursor)
{
    this->setFillColor(cursor.getFillColor());
    this->setOutlineColor(cursor.getOutlineColor());
    this->setOutlineThickness(cursor.getOutlineThickness());
    this->setSize(cursor.getSize());
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
