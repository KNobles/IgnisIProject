#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>

#include "TileMap.h"
#include "StateMachine.h"
#include "InputManager.h"
#include "Selector.h"
#include "GameDimens.h"
#include "CharacterSprite.h"
#include "Warrior.h"

struct GameData
{
    StateMachine machine;
    sf::RenderWindow window;
    sf::View view;
        Warrior *jeanne;
        CharacterSprite c;
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
//        std::vector<CharacterSprite*> chars;
        GameDataRef data = std::make_shared<GameData>();
        Selector selector;
        TileMap map;
        void run();
        void moveView();

};

#endif // GAME_H
