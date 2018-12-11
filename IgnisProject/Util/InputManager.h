#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <vector>
#include <cmath>
#include "Selector.h"
#include "CharacterSprite.h"
class InputManager
{
    public:
        InputManager() {}
        virtual ~InputManager(){}

        bool isCharacterSelected(CharacterSprite&, Selector&);
        void moveCharacter(CharacterSprite*, Selector&);

    protected:

    private:
        void displayMovement(CharacterSprite&, sf::RenderWindow&);
};

#endif // INPUTMANAGER_H
