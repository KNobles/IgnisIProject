#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "StateMachine.h"
#include "InputManager.h"
#include <string>
#include "TileMap.h"
#include "Selector.h"
#include "GameDimens.h"

struct GameData
{
    StateMachine machine;
    sf::RenderWindow window;
    sf::View view;
//    InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
    public:
        Game(int width, int height, std::string title);
        virtual ~Game();
//        Game(const Game& other);
//        Game& operator=(const Game& other);

    private:
        // Updates run at 60 per second.
//        const float deltaTime = 1.f / 60.f;
//        sf::Clock clock;
        GameDataRef data = std::make_shared<GameData>();
        Selector selector;
        TileMap map;
        void run();
        void moveView();
};

#endif // GAME_H
