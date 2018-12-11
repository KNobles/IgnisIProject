#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "Game.h"
#include "GameDimens.h"

using std::string;
class MenuState: public State
{
    public:
        MenuState(GameDataRef);
        virtual ~MenuState();
        MenuState(const MenuState& other);
        MenuState& operator=(const MenuState& other);
        void init();
        void handleInput();
        void draw(float dt);
        void update(float dt);
        void setNewText();
        void setTitleText();
    protected:

    private:
        GameDataRef data;
        sf::Clock clock;
        sf::View view;
        sf::Texture background;
        sf::Sprite backgroundImage;
        sf::Text newText;
        sf::Font newFont;
        sf::Text titleText;
        sf::Font titleFont;
};

#endif // MENUSTATE_H
