#include "InputManager.h"

void InputManager::moveCharacter(CharacterSprite& character, Selector& selector)
{
    if(character.getIsSelected())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            character.setIsSelected(false);
            std::cout << "Deslected" << std::endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sf::sleep(sf::milliseconds(100));
            int sum = abs(selector.getPosition().x - character.getPosition().x) / 16 + abs(selector.getPosition().y - character.getPosition().y) /16;
//            std::cout << "From : " << character.getPosition().x << ", " << character.getPosition().y << std::endl;
            std::cout << "Sum : " << sum << std::endl;
//            displayMovement(character, selector);
            if(selector.getPosition() != character.getPosition() && sum <= character.getCharacter()->getMovement())
            {
                character.setPosition(selector.getPosition());
//                std::cout << "To : " << character.getPosition().x << ", " << character.getPosition().y << std::endl;
                character.setIsSelected(false);
                sum = 0;
            }
        }
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && character.getPosition() == selector.getPosition())
        {
            std::cout << "Selected" << std::endl;
            character.setIsSelected(true);
        }
    }
}

void InputManager::displayMovement(CharacterSprite& character, sf::RenderWindow& window)
{
    if(character.getIsSelected())
    {
        const sf::Vector2f tileSize(16.f, 16.f);
        std::vector<sf::RectangleShape*> movements;
        for(int i = 0; i <= character.getCharacter()->getMovement(); i++)
        {
            sf::RectangleShape* rect = new sf::RectangleShape(tileSize);
            rect->setFillColor(sf::Color::Blue);
            movements.push_back(rect);
        }
        for(unsigned int x = 0; x < movements.size(); x++)
        {
            movements[x]->move(x*16.f, x*16.f);
            window.draw(*movements[x]);
        }

    }
}
