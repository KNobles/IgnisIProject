#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "TileMap.h"
#include "Warrior.h"
#include "Selector.h"
#include "Animation.h"
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
    Selector myCursor("selectorAnimated.png");
    sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));

    view.setViewport(sf::FloatRect(0, 0, 2.f, 2.f));
    Animation animation(&myCursor.getTexture(), sf::Vector2u(2, 1), 1.f);
    float deltaTime = .0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            myCursor.updatePosition();
//            cout << "VIEW: " << view.getCenter().x << endl;

        }

        animation.update(0, deltaTime);
        myCursor.setTextureRect(animation.uvRect);
        window.clear();
        window.setView(view);
        sf::RectangleShape x(sf::Vector2f(16.f,16.f));
        x.setFillColor(sf::Color::Red);
        window.draw(x);
        window.draw(map);
        window.draw(myCursor);
        window.display();
    }

//    Warrior *w1 = new Warrior("Kevin");
//    cout<<w1->str()<<endl;
//    w1->addExp(320);
//    cout<<w1->str()<<endl;

//    Warrior *w2 = new Warrior("Axel");
//    combat(*w1, *w2);


    return 0;
}
