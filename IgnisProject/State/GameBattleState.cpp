#include "GameBattleState.h"

GameBattleState::GameBattleState(GameDataRef data)
{
    this->data = data;
}

void GameBattleState::init()
{
    this->view.setSize(WIDTH/2, HEIGHT/2);
    this->view.setCenter(WIDTH/4, HEIGHT/4);
    this->view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
    this->map.loadLevel1();
}

void GameBattleState::handleInput()
{
    sf::Event event;
        while (data->window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                data->window.close();

            moveView();
        }

}

void GameBattleState::update(float deltaTime)
{

}

void GameBattleState::draw(float deltaTime)
{
        data->window.clear();
        data->window.draw(this->map);
        data->window.draw(this->selector);
        data->window.setView(this->view);
        data->window.display();
}

void GameBattleState::moveView()
{
    selector.updatePosition();

    if(selector.getPosition().x > this->view.getCenter().x - 16.f && this->view.getCenter().x*1.28 < WIDTH) // à changer plus tard (1.28)
    {
       this->view.move(16.f, 0);
    }
    if(selector.getPosition().x < this->view.getCenter().x && this->view.getCenter().x > WIDTH/4)
    {
       this->view.move(-16.f, 0);
    }
    if(selector.getPosition().y > this->view.getCenter().y && this->view.getCenter().y*1.28 < HEIGHT)
    {
       this->view.move(0, 16);
    }
    if(selector.getPosition().y < this->view.getCenter().y && this->view.getCenter().y > HEIGHT/4)
    {
       this->view.move(0, -16);
    }
}
