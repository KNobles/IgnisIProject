#include "InputManager.h"
#include "GameDimens.h"

/**
Fonction permettant de selectionner et déplacer un personnage en fonction de ses points de mouvements
*/
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

            while(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                sf::sleep(sf::milliseconds(100));
            }
            int sum = abs(selector.getPosition().x - character->getPosition().x) / PIXEL_SIZE + abs(selector.getPosition().y - character->getPosition().y) /PIXEL_SIZE;

            std::cout << "Sum : " << sum << std::endl;
            if(sum <= character->getCharacter()->getMovement())
            {
                character->setPosition(selector.getPosition());

                sum = 0;
                for(CharacterSprite* c:ennemies)
                {
                    int distX = c->getPosition().x - character->getPosition().x;
                    int distY = c->getPosition().y - character->getPosition().y;
                    std::cout << distX << " " << distY << endl;
                    int dist = (int(std::sqrt(std::pow(distX, 2) + std::pow(distY, 2))));
                    std::cout << dist << endl;
                    if(dist - character->getCharacter()->getWeapon()->getRange()*PIXEL_SIZE == 0 || dist/10 - character->getCharacter()->getWeapon()->getRange() == 0)
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
