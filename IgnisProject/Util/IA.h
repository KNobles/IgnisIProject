#ifndef IA_H
#define IA_H
#include "CharacterSprite.h"
#include "TeamSprite.h"


class IA
{
    public:
        IA(TeamSprite ally);
        virtual ~IA();
        IA(const IA& other);
        IA& operator=(const IA& other);

    protected:

    private:
        CharacterSprite ch;
        TeamSprite teamAlly;
        void moveIA();
        void attackIA();
        CharacterSprite chooseTargetIA();
};

#endif // IA_H
