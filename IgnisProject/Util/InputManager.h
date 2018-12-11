#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <vector>
#include <cmath>
#include "Selector.h"
#include "GameDimens.h"
#include "CharacterSprite.h"
#include "math.h"
#include "Character.h"
class InputManager
{
    public:
        InputManager() {}
        virtual ~InputManager(){}

        bool isCharacterSelected(CharacterSprite&, Selector&);
        void moveCharacter(CharacterSprite*, Selector&, vector<CharacterSprite*> ennemies);

    protected:

    private:
        void displayMovement(CharacterSprite&, sf::RenderWindow&);
};

#endif // INPUTMANAGER_H
