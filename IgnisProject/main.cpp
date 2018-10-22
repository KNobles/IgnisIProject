#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "TileMap.h"
#include "Warrior.h"

using namespace std;
void create(){
    Warrior *w = new Warrior();
}

int main()
{
    int width = 512;
    int height = 512;
    sf::RenderWindow window(sf::VideoMode(width, height), "TileMap test");
    window.setFramerateLimit(60);
    sf::CircleShape shape(8.f);
    shape.setFillColor(sf::Color::Green);
    const int level[] =
    {
        32, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("Assets/Sprites/Tiles/Arcadia Temple.png", sf::Vector2u(16, 16), level, 16, 8))
        return -1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && shape.getPosition().y+16 < height)
            {
                shape.move(0,16.f);
                cout << "x: " << shape.getPosition().x << " y: " << shape.getPosition().y << endl;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && shape.getPosition().y > 0)
            {
                shape.move(0,-16.f);
                cout << "x: " << shape.getPosition().x << " y: " << shape.getPosition().y << endl;            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && shape.getPosition().x+16 < width)
            {
                shape.move(16.f, 0);
                cout << "x: " << shape.getPosition().x << " y: " << shape.getPosition().y << endl;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && shape.getPosition().x > 0)
            {
                shape.move(-16.f, 0);
                cout << "x: " << shape.getPosition().x << " y: " << shape.getPosition().y << endl;
            }
        }

        window.clear();
        window.draw(map);
        window.draw(shape);
        window.display();
    }



    Warrior *w1 = new Warrior();

    std::cout << w1->str();


    return 0;
}
