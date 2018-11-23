#include "InputManager.h"

bool InputManager::isCharacterSelected(CharacterSprite& character, Selector& selector, sf::RenderWindow& window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && character.getIsSelected())
    {
            moveCharacter(character, selector);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !character.getIsSelected())
    {
        if(selector.getPosition() == character.getPosition())
        {
            std::cout << character.getCharacter()->str() << std::endl;
            character.setIsSelected(true);
            return true;
        }
    }
    return false;
}

void InputManager::moveCharacter(CharacterSprite& character, Selector& selector)
{
        character.setPosition(selector.getPosition());
        character.setIsSelected(false);
}
