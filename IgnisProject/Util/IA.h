#ifndef IA_H
#define IA_H
#include "CharacterSprite.h"
#include "Game.h"


class IA
{
    public:
        IA(GameDataRef);
        virtual ~IA();
        IA(const IA& other);
        IA& operator=(const IA& other);

    protected:

    private:
        CharacterSprite ch;
        void moveIA();
        void attackIA();
        void chooseTargetIA();
        GameDataRef data;

};

#endif // IA_H
