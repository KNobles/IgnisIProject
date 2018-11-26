#include "Game.h"
#include "GameBattleState.h"
Game::Game(int width, int height, std::string title)
{
    data->window.create(sf::VideoMode(width, height), title);
    data->machine.addState(stateRef(new GameBattleState(this->data)));

//    data->view.setSize(width/2, height/2);
//    data->view.setCenter(width/4, height/4);
//    data->view.setViewport(sf::FloatRect(0, 0, 2.f, 2.f));
//    data->map.loadLevel1();

    this->run();
}

void Game::run()
{

    float newTime, frameTime, interpolation;
    float currentTime = this->clock.getElapsedTime().asSeconds();
    float accumulator = 0.f;

    while (data->window.isOpen())
    {
        this->data->machine.processStateChanges();
        newTime = this->clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;
        if(frameTime > 0.25f)
        {
            frameTime = 0.25f;
        }

        currentTime = newTime;
        accumulator += frameTime;
        while(accumulator >= deltaTime)
        {
            this->data->machine.getActiveState()->handleInput();
            this->data->machine.getActiveState()->update(deltaTime);
            accumulator -= deltaTime;
        }
        interpolation = accumulator/deltaTime;
        this->data->machine.getActiveState()->draw(interpolation);
    }

    /*
     while (data->window.isOpen())
     {
        sf::Event event;
        while (data->window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                data->window.close();

            moveView();
        }
            data->window.clear();
        data->window.draw(data->map);
        data->window.draw(data->selector);
        data->window.setView(data->view);
        data->window.display();


     }
     */
}

/*
void Game::moveView()
{
    data->selector.updatePosition();

    if(data->selector.getPosition().x > data->view.getCenter().x - 16.f && data->view.getCenter().x*1.28 < WIDTH) // à changer plus tard (1.28)
    {
       data->view.move(16.f, 0);
    }
    if(data->selector.getPosition().x < data->view.getCenter().x && data->view.getCenter().x > WIDTH/4)
    {
       data->view.move(-16.f, 0);
    }
    if(data->selector.getPosition().y > data->view.getCenter().y && data->view.getCenter().y*1.28 < HEIGHT)
    {
       data->view.move(0, 16);
    }
    if(data->selector.getPosition().y < data->view.getCenter().y && data->view.getCenter().y > HEIGHT/4)
    {
       data->view.move(0, -16);
    }
}
*/
