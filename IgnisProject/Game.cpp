#include "Game.h"

Game::Game(int width, int height, std::string title)
{
    data->window.create(sf::VideoMode(width, height), title);
    data->view.setSize(width/2, height/2);
    data->view.setCenter(width/4, height/4);
    data->view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
    data->window.setFramerateLimit(60);
    this->run();
}

Game::~Game()
{
    //dtor
}

void Game::run()
{
//    sf::Sprite sprite;
//    sf::Texture texture;
//    texture.loadFromFile("Assets/Sprites/Character/Roy/Roy-idle.png");
//    sprite.setTexture(texture);
//    sprite.setPosition(0, 0);
//    sprite.setOrigin(0,0);
    map.loadLevel1();
    while (data->window.isOpen())
    {
        sf::Event event;
        while (data->window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                data->window.close();

            moveView();
            sf::Vector2f vect = data->view.getCenter();
            std::cout << vect.y << endl;
        }

        data->window.clear();
        data->window.draw(map);
        data->window.draw(selector);
        data->window.setView(data->view);

        data->window.display();
    }
}

void Game::moveView()
{
    selector.updatePosition();

//    data->view.setCenter(selector.getPosition());
    if(selector.getPosition().x > data->view.getCenter().x - 16.f && data->view.getCenter().x*1.28 < WIDTH) // à changer plus tard (1.28)
    {
       data->view.move(16.f, 0);
    }
    if(selector.getPosition().x < data->view.getCenter().x && data->view.getCenter().x > WIDTH/4)
    {
       data->view.move(-16.f, 0);
    }
    if(selector.getPosition().y > data->view.getCenter().y && data->view.getCenter().y*1.28 < HEIGHT)
    {
       data->view.move(0, 16);
    }
    if(selector.getPosition().y < data->view.getCenter().y && data->view.getCenter().y > HEIGHT/4)
    {
       data->view.move(0, -16);
    }
}
//
//Game::Game(const Game& other)
//{
//    copy ctor
//}
//
//Game& Game::operator=(const Game& rhs)
//{
//    if (this == &rhs) return *this; // handle self assignment
//    assignment operator
//    return *this;
//}
