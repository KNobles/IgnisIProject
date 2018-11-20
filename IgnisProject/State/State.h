#ifndef STATE_H
#define STATE_H


class State
{
    public:
        virtual void init() = 0;

        virtual void handleInput() = 0;
        virtual void update() = 0;
        virtual void draw(float deltaTime) = 0;

        virtual void pause(){}
        virtual void resume(){}
};

#endif // STATE_H
