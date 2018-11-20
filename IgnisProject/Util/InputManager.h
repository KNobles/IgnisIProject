#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "Selector.h"
#include "CharacterSprite.h"
class InputManager
{
    public:
        InputManager() {}
        virtual ~InputManager(){}

        bool isCharacterSelected(CharacterSprite&,Selector& selector, sf::RenderWindow& window);
        sf::Vector2i getSelectorPosition(Selector& selector);

    protected:

    private:
};

#endif // INPUTMANAGER_H
