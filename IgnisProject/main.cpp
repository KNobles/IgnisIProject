#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "TileMap.h"
#include "Warrior.h"
#include "Cursor.h"
#include<sstream>
#include<fstream>
#include<iomanip>
#include<time.h>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 608;

int main()
{
    TileMap map;
    map.loadLevel1();

    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TileMap test");
    window.setFramerateLimit(60);
    Cursor myCursor(16.f,1.f, sf::Color::Red);
    sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));
    view.setViewport(sf::FloatRect(0, 0, 2.f, 2.f));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            myCursor.setMovement();
        }

        window.clear();
        window.setView(view);
        window.draw(map);
        window.draw(myCursor);
        window.display();
    }
//
//    Warrior *w1 = new Warrior("Kevin");
//    Warrior *w2 = new Warrior("Axel");
//
//
//
//    combat(*w1, *w2);


    return 0;
}
