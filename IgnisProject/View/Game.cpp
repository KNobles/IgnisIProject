#define _WIN32_WINNT 0x0500
#include "Game.h"
#include "GameBattleState.h"
#include "MenuState.h"
#include "CreditState.h"
#include "GameoverState.h"
#include "windows.h"
#include <iostream>
Game::Game(int width, int height, std::string title)
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);
    data->window.create(sf::VideoMode(width, height), title);
    data->machine.addState(stateRef(new MenuState(this->data)));
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
