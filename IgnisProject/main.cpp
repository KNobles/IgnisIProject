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

    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TileMap test");
    window.setFramerateLimit(60);
    Cursor myCursor(8.f, 1.5f,  sf::Color::Red);
    sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));
    view.setViewport(sf::FloatRect(0, 0, 2.5f, 2.5f));

    ifstream infile("Assets/Sprites/Tiles/map1.txt", ios::in);
    cout << "AVANT" << endl;
    int x,y;
    infile >> x >> y;
    int lvl[x] = {0};
    for(int i = 0; i <= y; i++)
    {
        for(int j = 0; j <= x; j++)
        {
            infile >> lvl[j];
            cout << lvl[j];
        }
        cout << endl;
    }

    const int level[] =
    {
        705, 705, 96, 487, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
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

    cout << "APRES" << endl;
        for(int i = 0; i <= y; i++)
    {
        for(int j = 0; j <= x; j++)
        {
            cout << lvl[j];
        }
        cout << endl;
    }

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

    Warrior *w1 = new Warrior("Kevin");
    Warrior *w2 = new Warrior("Axel");



    combat(*w1, *w2);

    cout << w1->str();
    cout << w2->str();


    return 0;
}
