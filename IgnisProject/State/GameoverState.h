#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "Game.h"
#include "GameDimens.h"

class GameoverState: public State
{
    public:
        GameoverState(GameDataRef);
        virtual ~GameoverState();
        GameoverState(const GameoverState& other);
        GameoverState& operator=(const GameoverState& other);
        void init();
        void handleInput();
        void moveSelector();
        void draw(float dt);
        void update(float dt);
        void setGameOverText();

    protected:

    private:
        GameDataRef data;
        sf::Clock clock;
        sf::View view;
        sf::Texture backgroundGameOver;
        sf::Sprite backgroundImageGameOver;
        sf::Text gameoverText;
        sf::Font gameoverFont;
};
#endif // GAMEOVERSTATE_H
