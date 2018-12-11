#include "Game.h"
#include "GameBattleState.h"
#include "MenuState.h"
#include "GameoverState.h"
Game::Game(int width, int height, std::string title)
{
    data->window.create(sf::VideoMode(width, height), title);
<<<<<<< HEAD
    data->machine.addState(stateRef(new GameBattleState(this->data)));
=======
    data->machine.addState(stateRef(new MenuState(this->data)));
>>>>>>> 08ce0446e3886cf9d44003058f52b91c989bcc40
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
