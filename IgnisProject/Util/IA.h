#ifndef IA_H
#define IA_H
#include "CharacterSprite.h"


class IA
{
    public:
        IA();
        virtual ~IA();
        IA(const IA& other);
        IA& operator=(const IA& other);

    protected:

    private:
        CharacterSprite ch;
        void moveIA(CharacterSprite,GameDataRef);
        void attackIA();
        void chooseTargetIA();
        GameDataRef data;

};

#endif // IA_H
