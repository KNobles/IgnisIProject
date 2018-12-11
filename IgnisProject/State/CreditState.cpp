#include "CreditState.h"
#include "MenuState.h"
#include <SFML\Graphics.hpp>

CreditState::CreditState(GameDataRef data)
{
    this->data=data;
    this->background.loadFromFile("Assets/Background/Menu.jpg");
    this->backgroundImage.setTexture(this->background);
    this->newFont.loadFromFile("Assets/Font/Dearest/Dearest.ttf");
    this->setNewText();
    this->titleFont.loadFromFile("Assets/Font/Kingthings-Italique/Kingthings_Italique.ttf");
    this->setTitleText();

}

CreditState::~CreditState()
{
    //dtor
}

CreditState::CreditState(const CreditState& other)
{
    //copy ctor
}

CreditState& CreditState::operator=(const CreditState& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void CreditState::setNewText(){
    newText.setFont(titleFont);
    newText.setStyle(sf::Text::Bold);
    newText.setString("Jeu réalisé par Axel Lux, Kevin Nobles,\nAlexandre Rocroix.\nétudiants de la HELHa Campus Mons,\ndans le cadre du cours de Mr. V. Altares.");
    newText.setFillColor(sf::Color::Black);
    newText.setCharacterSize(20);
    newText.setPosition(10.0f, 250.0f);

}

void CreditState::init()
{
    this->view.setSize(WIDTH/2, HEIGHT/2);
    this->view.setCenter(WIDTH/4, HEIGHT/4);
    this->view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
    data->window.setKeyRepeatEnabled(false);
}

void CreditState::setTitleText(){
    titleText.setFont(titleFont);
    titleText.setStyle(sf::Text::Bold);
    titleText.setString("Ignis Insigne");
    titleText.setFillColor(sf::Color::Black);
    titleText.setCharacterSize(96);
    titleText.setPosition(80.0f, 60.0f);

}

void CreditState::handleInput()
{
    sf::Event event;
        while (data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                data->window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                data->machine.addState(stateRef(new MenuState(data)), true);
            }


        }
}

void CreditState::draw(float deltaTime)
{
        data->window.clear();
        data->window.draw(backgroundImage);
        data->window.draw(titleText);
        data->window.draw(newText);
        data->window.display();
}
void CreditState::update(float deltaTime)
{

}
