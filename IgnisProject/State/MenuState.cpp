#include "MenuState.h"
#include <SFML\Graphics.hpp>

#include <string>
#include <iostream>

MenuState::MenuState(GameDataRef data)
{
    this->data=data;
    this->background.loadFromFile("Assets/Background/Menu.jpg");
    this->backgroundImage.setTexture(this->background);
    this->newFont.loadFromFile("Assets/Font/Dearest/Dearest.ttf");
    this->setNewText();
    this->titleFont.loadFromFile("Assets/Font/Kingthings-Italique/Kingthings_Italique.ttf");
    this->setTitleText();


}

MenuState::~MenuState()
{
    //dtor
}
void MenuState::setNewText(){
    newText.setFont(newFont);
    newText.setStyle(sf::Text::Bold);
    newText.setString("Press enter \nto continue");
    newText.setFillColor(sf::Color::Black);
    newText.setCharacterSize(48);
    newText.setPosition(125.0f, 250.0f);

}
void MenuState::setTitleText(){
    titleText.setFont(titleFont);
    titleText.setStyle(sf::Text::Bold);
    titleText.setString("Ignis Insigne");
    titleText.setFillColor(sf::Color::Black);
    titleText.setCharacterSize(96);
    titleText.setPosition(80.0f, 60.0f);

}

MenuState::MenuState(const MenuState& other)
{
    //copy ctor
}

MenuState& MenuState::operator=(const MenuState& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void MenuState::init()
{
    this->view.setSize(WIDTH/2, HEIGHT/2);
    this->view.setCenter(WIDTH/4, HEIGHT/4);
    this->view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
    data->window.setKeyRepeatEnabled(false);
}
void MenuState::handleInput()
{
    sf::Event event;
        while (data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                data->window.close();
        }
}
void MenuState::moveSelector()
{
}
void MenuState::draw(float deltaTime)
{
        data->window.clear();
        data->window.draw(backgroundImage);
        data->window.draw(titleText);
        data->window.draw(newText);
        data->window.display();
}
void MenuState::update(float deltaTime)
{

}

