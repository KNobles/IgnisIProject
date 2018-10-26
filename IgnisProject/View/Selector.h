#ifndef SELECTOR_H
#define SELECTOR_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;
class Selector : public sf::Sprite
{
    public:
        Selector(std::string name);
        virtual ~Selector();
        Selector& operator=(const Selector& cursor);
        Selector(const Selector& cursor);
        void updatePosition();
        sf::Texture& getTexture();

    protected:

    private:
        std::string name;
        sf::Texture texture;

};

#endif // CURSOR_H
