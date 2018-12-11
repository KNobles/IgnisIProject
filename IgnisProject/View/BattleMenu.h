#include <SFML/Graphics.hpp>

#ifndef BATTLEMENU_H
#define BATTLEMENU_H

#define MAX_NUMBER_OF_ITEMS 2

class BattleMenu
{
    public:
        BattleMenu(float width=30.f, float height=30.f0);
        virtual ~BattleMenu();

        void draw(sf::RenderWindow&);
        void moveUp();
        void moveDown();

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

#endif // BATTLEMENU_H
