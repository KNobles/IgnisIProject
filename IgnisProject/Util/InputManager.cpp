#include "InputManager.h"

void InputManager::moveCharacter(CharacterSprite* character, Selector& selector, vector<CharacterSprite*> ennemies)
{

    if(character->getIsSelected())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            character->setIsSelected(false);
            std::cout << "Deselected" << std::endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
<<<<<<< HEAD
            sf::sleep(sf::milliseconds(100));
            int sum = abs(selector.getPosition().x - character.getPosition().x) / PIXEL_SIZE + abs(selector.getPosition().y - character.getPosition().y) /PIXEL_SIZE;
=======
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                sf::sleep(sf::milliseconds(100));
            }
            int sum = abs(selector.getPosition().x - character->getPosition().x) / 16 + abs(selector.getPosition().y - character->getPosition().y) /16;
>>>>>>> 08ce0446e3886cf9d44003058f52b91c989bcc40
//            std::cout << "From : " << character.getPosition().x << ", " << character.getPosition().y << std::endl;
            std::cout << "Sum : " << sum << std::endl;
//            displayMovement(character, selector);
            if(sum <= character->getCharacter()->getMovement())
            {
                character->setPosition(selector.getPosition());
//                std::cout << "To : " << character.getPosition().x << ", " << character.getPosition().y << std::endl;

                sum = 0;
                for(CharacterSprite* c:ennemies)
                {
                    int distX = c->getPosition().x - character->getPosition().x;
                    int distY = c->getPosition().y - character->getPosition().y;
                    std::cout << distX << " " << distY << endl;
                    int dist = (int(std::sqrt(std::pow(distX, 2) + std::pow(distY, 2))));
                    std::cout << dist << endl;
                    if(dist - character->getCharacter()->getWeapon()->getRange()*16 == 0 || dist/10 - character->getCharacter()->getWeapon()->getRange() == 0)
                    {
                        std::cout << "Combat" << endl;
                        combat(*character->getCharacter(), *c->getCharacter(), character->getCharacter()->getWeapon()->getRange());
                        character->setIsSelected(false);
                        character->setIsDone(true);
                        if(c->getCharacter()->getHealth()<=0)
                        {
                            c->getCharacter()->die();
                        }
                        return;
                    }
                }
                character->setIsSelected(false);
                character->setIsDone(true);
            }
        }
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && character->getPosition() == selector.getPosition())
        {
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                sf::sleep(sf::milliseconds(100));
            }
            std::cout << "Selected" << std::endl;
            character->setIsSelected(true);
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
