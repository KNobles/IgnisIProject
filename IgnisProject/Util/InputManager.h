#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "Selector.h"
#include "CharacterSprite.h"
class InputManager
{
    public:
        InputManager() {}
        virtual ~InputManager(){}

        bool isCharacterSelected(CharacterSprite&, Selector&, sf::RenderWindow&);
        void moveCharacter(CharacterSprite&, Selector&);

    protected:

    private:
};

#endif // INPUTMANAGER_H
