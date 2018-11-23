#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include<sstream>
#include<fstream>
#include<iomanip>
#include<time.h>
#include <iostream>

#include "GameDimens.h"
#include "Game.h"

using namespace std;

int main()
{
    Game game(WIDTH, HEIGHT, "Ignis");
//    TileMap map;
//    map.loadLevel1();
////    Game game(WIDTH, HEIGHT, "Fire emblem");
//    srand(time(NULL));
//    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TileMap test");
//    window.setFramerateLimit(60);
//    Selector myCursor("selectorAnimated.png");
//    sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));
//
//    view.setViewport(sf::FloatRect(0, 0, 2.f, 2.f));
//    Animation animation(&myCursor.getTexture(), sf::Vector2u(2, 1), 1.f);
//    float deltaTime = .0f;
//    sf::Clock clock;
//
//    while (window.isOpen())
//    {
//        deltaTime = clock.restart().asSeconds();
//
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//
//            if (event.type == sf::Event::Closed)
//                window.close();
//            myCursor.updatePosition();
////            cout << "VIEW: " << view.getCenter().x << endl;
//
//        }
//
//        animation.update(0, deltaTime);
//        myCursor.setTextureRect(animation.uvRect);
//        window.clear();
//        window.setView(view);
//        sf::RectangleShape x(sf::Vector2f(16.f,16.f));
//        x.setFillColor(sf::Color::Red);
//        window.draw(x);
//        window.draw(map);
//        window.draw(myCursor);
//        window.display();
//    }
    /*
    Warrior *w1 = new Warrior("Kevin");
    Warrior *w2 = new Warrior("Alexandre");
    cout<<w1->str()<<endl;
    Archer *a1 = new Archer("Axel");
    cout<<a1->str()<<endl;
    a1->addExp(320);
    cout<<a1->str()<<endl;
    cout<<"----------------Combat---------"<<endl;
    combat(*w1, *w2);
    cout<<"----------------Result---------"<<endl;
    cout<<w1->str()<<endl;
    cout<<w2->str()<<endl;*/



    return 0;
}
