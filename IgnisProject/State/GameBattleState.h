#ifndef GAMEBATTLESTATE_H
#define GAMEBATTLESTATE_H
#include "Game.h"
#include "GameDimens.h"
#include "TileMap.h"
#include <vector>
#include "Warrior.h"
#include "AnimatedSprite.h"

class GameBattleState : public State
{
    public:
        GameBattleState(GameDataRef);
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);

    protected:

    private:
        void moveView();
        void moveSelector();
        void showMovement(CharacterSprite&);

        Warrior* w;
        CharacterSprite ch;
        GameDataRef data;
        sf::Clock clock;
        Selector selector;
        TileMap map;
        sf::View view;

        Animation walkingAnimationUp;
        Animation walkingAnimationDown;
        Animation walkingAnimationLeft;
        Animation walkingAnimationRight;

        Animation* currentAnimation = &walkingAnimationDown;
        AnimatedSprite animatedSprite;

};

#endif // GAMEBATTLESTATE_H
