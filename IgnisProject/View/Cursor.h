#ifndef CURSOR_H
#define CURSOR_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace std;
class Cursor : public sf::RectangleShape
{
    public:
        Cursor(float size, float thickness, sf::Color color);
        Cursor();
//        Cursor(float size=16.f, float thickness=1.f, sf::Color color=sf::Color::Blue);
        virtual ~Cursor();
        Cursor& operator=(const Cursor& cursor);
        Cursor(const Cursor& cursor);
        void setMovement();

    protected:

    private:

};

#endif // CURSOR_H
