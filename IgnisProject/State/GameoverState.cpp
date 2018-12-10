#include "GameoverState.h"
#include <SFML\Graphics.hpp>

#include <string>
#include <iostream>

GameoverState::GameoverState(GameDataRef data)
{
    this->data=data;
    this->backgroundGameOver.loadFromFile("Assets/Background/GameOver.jpg");
    this->backgroundImageGameOver.setTexture(this->backgroundGameOver);
    this->gameoverFont.loadFromFile("Assets/Font/Dearest/Dearest.ttf");
    this->setGameOverText();
}

GameoverState::~GameoverState()
{
    //dtor
}

GameoverState::GameoverState(const GameoverState& other)
{
    //copy ctor
}

GameoverState& GameoverState::operator=(const GameoverState& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
void GameoverState::setGameOverText(){
    gameoverText.setFont(gameoverFont);
    gameoverText.setStyle(sf::Text::Bold);
    gameoverText.setString("Game Over");
    gameoverText.setFillColor(sf::Color::Red);
    gameoverText.setCharacterSize(65);
    gameoverText.setPosition(100.0f, 200.0f);

}
void GameoverState::init()
{
    this->view.setSize(WIDTH/2, HEIGHT/2);
    this->view.setCenter(WIDTH/4, HEIGHT/4);
    this->view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
    data->window.setKeyRepeatEnabled(false);
}
void GameoverState::handleInput()
{
    sf::Event event;
        while (data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                data->window.close();
        }
}
void GameoverState::moveSelector()
{
}
void GameoverState::draw(float deltaTime)
{
        data->window.clear();
        data->window.draw(backgroundImageGameOver);
        data->window.draw(gameoverText);

        data->window.display();
}
void GameoverState::update(float deltaTime)
{

}

