#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "TileMap.h"
#include "Warrior.h"
#include "Archer.h"
#include "Knight.h"
#include "Mage.h"
#include "Selector.h"
#include "Team.h"
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

/*
    Archer *a1 = new Archer("Alex");
    cout<<a1->str()<<endl;
    a1->addExp(320);
    cout<<a1->str()<<endl;
    Warrior *w1 = new Warrior("Kevin");
    Warrior *w2 = new Warrior("Alexandre");
    cout<<w1->str()<<endl;
    cout<<a1->str()<<endl;
    a1->addExp(320);
    cout<<a1->str()<<endl;
    cout<<"----------------Combat---------"<<endl;
    combat(*w1, *w2);
    cout<<"----------------Result---------"<<endl;
    cout<<"----------------Avant Up---------"<<endl;
    cout<<w1->str()<<endl;
    cout<<w2->str()<<endl;
    cout<<"----------------Apres Up---------"<<endl;
    w1->addExp(320);
    w2->addExp(6500);
    cout<<w1->str()<<endl;
    cout<<w2->str()<<endl;
    Knight *k1 = new Knight("Axel");
    cout<<k1->str()<<endl;
    k1->addExp(320);
    cout<<k1->str()<<endl;

    Mage *m1 = new Mage("Luana");
    cout<<m1->str()<<endl;
    m1->addExp(1235);
    cout<<m1->str()<<endl;

    Team *t = Team::getInstance();
    t->add(w1);
    t->add(w2);
    t->add(a1);
    cout << t->getTeam().size() << endl;
    t->add(w1);


    t->remove(w2);

    cout<<w2->str()<<endl;


    cout << t->getTeam().size() << endl;
*/


    return 0;
}
