#ifndef CURSOR_H
#define CURSOR_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace std;
class Cursor : public sf::CircleShape
{
    public:
        Cursor(float radius, sf::Color color);
        virtual ~Cursor();
        void setMovement();

    protected:

    private:

};

#endif // CURSOR_H
