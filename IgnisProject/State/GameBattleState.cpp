#include "GameBattleState.h"

GameBattleState::GameBattleState(GameDataRef data)
{

    this->data = data;
    Character* cavalier = new Cavalier("Georgette");
    ch2 = new CharacterSprite(cavalier);

    allies.push_back(ch2);
    allies.push_back(&ch);
    allies[1]->setPosition(sf::Vector2f(16,16));

    Character* archer = new Archer("Axel");
    Character* knight = new Knight("Orlermo");
    CharacterSprite* ch3 = new CharacterSprite(archer);
    CharacterSprite* ch4 = new CharacterSprite(knight);
    ennemies.push_back(ch3);
    ennemies.push_back(ch4);
    ennemies[0]->setPosition(sf::Vector2f(192,192));
    ennemies[1]->setPosition(sf::Vector2f(192,208));

    allyTurn=true;

//    this->w = new Warrior("jeanne");
//    this->ch(w);
}

void GameBattleState::init()
{
    this->view.setSize(WIDTH/2, HEIGHT/2);
    this->view.setCenter(WIDTH/4, HEIGHT/4);
    this->view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
    data->window.setKeyRepeatEnabled(false);
    this->map.loadLevel1();
//    data->window.setFramerateLimit(60);
//    data->window.setMouseCursorVisible(false);
}

void GameBattleState::handleInput()
{
    sf::Event event;
        while (data->window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                data->window.close();

            if(allyTurn)
            {
                for(CharacterSprite* c:allies)
                {
                    if((selector.getPosition() == c->getPosition() || c->getIsSelected()) && !c->getIsDone())
                    {
                        data->input.moveCharacter(c, this->selector, ennemies);
;                       for(unsigned int i=0; i<ennemies.size(); i++)
                        {
                            if(ennemies[i]->getCharacter()->isDead())
                            {
                                delete ennemies[i];
                                ennemies.erase(ennemies.begin() + i);
                                this->draw(60);
                            }
                        }
                        for(unsigned int i=0; i<allies.size(); i++)
                        {
                            if(allies[i]->getCharacter()->isDead())
                            {
                                delete allies[i];
                                allies.erase(allies.begin() + i);
                                this->draw(60);
                            }
                        }
                        endTurn();
                    }
                }


                moveView();
            }
            else
            {
                for(CharacterSprite* c:ennemies)
                {
                    if((selector.getPosition() == c->getPosition() || c->getIsSelected()) && !c->getIsDone())
                    {
                        data->input.moveCharacter(c, this->selector, allies);
                        for(unsigned int i=0; i<ennemies.size(); i++)
                        {
                            if(ennemies[i]->getCharacter()->isDead())
                            {
                                delete ennemies[i];
                                ennemies.erase(ennemies.begin() + i);
                                this->draw(60);
                            }
                        }
                        for(unsigned int i=0; i<allies.size(); i++)
                        {
                            if(allies[i]->getCharacter()->isDead())
                            {
                                delete allies[i];
                                allies.erase(allies.begin() + i);
                                this->draw(60);
                            }
                        }
                      /*  if(sf::Keyboard::isKeyPressed(d))
                            c->setIsDone(true);*/
                        endTurn();
                    }
                }


                moveView();
            }


        }

}

void GameBattleState::update(float deltaTime)
{

}

void GameBattleState::draw(float deltaTime)
{


        data->window.clear();
        data->window.draw(this->map);
        for(c:allies)
        {
            data->window.draw(*c);
        }
        for(c:ennemies)
        {
            data->window.draw(*c);
        }

        data->window.draw(this->selector);
        data->window.setView(this->view);
//
//            sf::Vector2f vect(16.f,16.f);
////            for(int i = 1; i <= ch.getCharacter()->getMovement(); i++)
////            {
////                sf::RectangleShape* rect = new sf::RectangleShape(vect);
////                rect->setFillColor(sf::Color::Black);
////                rect->setOrigin(i * 16.f, i * 16.f);
////                data->window.draw(*rect);
////            }
//                std::vector<sf::RectangleShape*> rects;
//                for(int i = 0; i < this->ch.getCharacter()->getMovement(); i ++)
//                {
//                    sf::RectangleShape rect(vect);
//                    rect.setFillColor(sf::Color::Black);
//                    rect.setOrigin(i * 16.f, i * 16.f);
////                    data->window.draw(*rect);
//                    rects.push_back(*rect);
//                }
//
//                for(int i = 0; i < rects.size(); i++)
//                {
//                    data->window.draw(*rects[i]);
//                }

        data->window.display();
}

void GameBattleState::moveView()
{
    moveSelector();

    if(selector.getPosition().x > this->view.getCenter().x - 16.f && this->view.getCenter().x*1.28 < WIDTH) // à changer plus tard (1.28)
    {
       this->view.move(16.f, 0);
    }
    if(selector.getPosition().x < this->view.getCenter().x && this->view.getCenter().x > WIDTH/4)
    {
       this->view.move(-16.f, 0);
    }
    if(selector.getPosition().y > this->view.getCenter().y && this->view.getCenter().y*1.28 < HEIGHT)
    {
       this->view.move(0, 16.f);
    }
    if(selector.getPosition().y < this->view.getCenter().y && this->view.getCenter().y > HEIGHT/4)
    {
       this->view.move(0, -16.f);
    }
}

void GameBattleState::moveSelector()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->selector.getPosition().y < HEIGHT)
    {
        this->selector.move(0,16.f);
        //cout << "x: " << this->getPosition().x << " y: " << this->getPosition().y << endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->selector.getPosition().y > 0)
    {
        this->selector.move(0,-16.f);
        //cout << "x: " << this->getPosition().x << " y: " << this->getPosition().y << endl;    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->selector.getPosition().x < WIDTH)
    {
        this->selector.move(16.f, 0);
        //cout << "x: " << this->getPosition().x << " y: " << this->getPosition().y << endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->selector.getPosition().x > 0)
    {
        this->selector.move(-16.f, 0);
        //cout << "x: " << this->getPosition().x << " y: " << this->getPosition().y << endl;
    }
}

void GameBattleState::showMovement(CharacterSprite& character)
{

}

void GameBattleState::endTurn()
{
    if(allyTurn)
    {
        for(CharacterSprite* c:allies)
        {
            if(!c->getIsDone())
            {
                return;
            }
        }
        allyTurn = !allyTurn;
        nextTurn();
    }
    else
    {
        for(CharacterSprite* c:ennemies)
        {
            if(!c->getIsDone())
            {
                return;
            }
        }
        allyTurn = !allyTurn;
        nextTurn();
    }

}

void GameBattleState::nextTurn()
{
    if(allyTurn)
    {
        for(CharacterSprite* c:allies)
        {
            c->setIsDone(false);
        }
    }
    else
    {
        for(CharacterSprite* c:ennemies)
        {
            c->setIsDone(false);
        }
    }

}


