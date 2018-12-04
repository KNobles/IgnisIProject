#include "Game.h"
#include "GameBattleState.h"
Game::Game(int width, int height, std::string title)
{
    data->window.create(sf::VideoMode(width, height), title);
    data->machine.addState(stateRef(new GameBattleState(this->data)));
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
}
