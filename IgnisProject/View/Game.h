#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>

#include "StateMachine.h"
#include "InputManager.h"

#include "GameDimens.h"
#include "CharacterSprite.h"
#include "Warrior.h"
#include "Mage.h"
#include "AssetManager.h"

struct GameData
{
    StateMachine machine;
    sf::RenderWindow window;
    InputManager input;
    AssetManager assets;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
    public:
        Game(int width, int height, std::string title);
    private:
        // Updates run at 60 per second.
        const float deltaTime = 1.f / 60.f;
        sf::Clock clock;
        GameDataRef data = std::make_shared<GameData>();
        void run();
};

#endif // GAME_H
