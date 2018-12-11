#ifndef GAMEBATTLESTATE_H
#define GAMEBATTLESTATE_H
#include "Game.h"
#include "GameDimens.h"
#include "TileMap.h"
#include <vector>
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "Cavalier.h"
#include "Knight.h"

class GameBattleState : public State
{
    public:
        GameBattleState(GameDataRef);
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
        void endTurn();
        void nextTurn();


    protected:

    private:
        void moveView();
        void moveSelector();
        void showMovement(CharacterSprite&);

        Warrior* w;
        CharacterSprite ch;
        CharacterSprite* ch2;
        vector<CharacterSprite*> v;
        GameDataRef data;
        sf::Clock clock;
        Selector selector;
        TileMap map;
        sf::View view;
};

#endif // GAMEBATTLESTATE_H
