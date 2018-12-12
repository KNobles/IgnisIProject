#ifndef CREDITSTATE_H
#define CREDITSTATE_H
#include "Game.h"
#include "GameDimens.h"


class CreditState: public State
{
    public:
        CreditState(GameDataRef);
        virtual ~CreditState();
        CreditState(const CreditState& other);
        CreditState& operator=(const CreditState& other);
        void init();
        void handleInput();
        void draw(float dt);
        void update(float dt);
        void setTitleText();
        void setNewText();

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

#endif // CREDITSTATE_H
