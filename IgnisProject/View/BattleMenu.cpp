#include "BattleMenu.h"

BattleMenu::BattleMenu(float width, float height)
{
    if(!font.loadFromFile("Assets/Font/arial.ttf"))
    {

    }

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Green);
    menu[0].setString("Attack");
    menu[0].setPosition(sf::Vector2f(width/2, height / (MAX_NUMBER_OF_ITEMS + 1)* 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Wait");
    menu[1].setPosition(sf::Vector2f(width/2, height / (MAX_NUMBER_OF_ITEMS + 1)* 2));

    selectedItemIndex = 0;

}

BattleMenu::~BattleMenu()
{
    //dtor
}

void BattleMenu::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}


void BattleMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void BattleMenu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
