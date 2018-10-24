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
int file(string &fileName)
{
    char newLine = '.';
    int numLines = 0;
    string text;
    ifstream openFile(fileName.c_str());

<<<<<<< HEAD
    cout << endl;

    if(!openFile)
    {
        cerr << "Error, file does not exist. " << endl;
        exit(EXIT_FAILURE);
    }
=======
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TileMap test");
    window.setFramerateLimit(60);
    Cursor myCursor(8.f, 1.5f,  sf::Color::Red);
    sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));
    view.setViewport(sf::FloatRect(0, 0, 2.5f, 2.5f));
>>>>>>> 4e9b8b8949fe492f0a02b1babe08b0b72cf81300

    while(getline(openFile, text, '\n'))
    {
        for(unsigned int i=0; i< text.length(); i++)
        {
            if(text.at(i) == newLine)
            {
                numLines++;
            }
        }
    }

    return numLines;
}


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
//
//    cout << w1->str();
//    cout << w2->str();
//    ifstream infile;
//    infile.open("Assets/Sprites/Tiles/map1.txt");
//    int n = file(infile);
//    cout << n << endl;


    return 0;
}
