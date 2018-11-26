#ifndef SELECTOR_H
#define SELECTOR_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "GameDimens.h"
using namespace std;
class Selector : public sf::Sprite
{
    public:
        Selector(std::string name="selector.png");
        virtual ~Selector();
        Selector& operator=(const Selector& cursor);
        Selector(const Selector& cursor);
//        void updatePosition();
        sf::Texture& getTexture();
    private:
        std::string name;
        sf::Texture texture;

};

#endif // CURSOR_H
