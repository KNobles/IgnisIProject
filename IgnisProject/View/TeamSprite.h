#ifndef TEAMSPRITE_H
#define TEAMSPRITE_H

#include <SFML/Graphics.hpp>
#include "CharacterSprite.h"
#include <vector>

using std::vector;

class TeamSprite
{
    public:
        TeamSprite(const Team& t);
        virtual ~TeamSprite();
        TeamSprite(const TeamSprite& other);
        TeamSprite& operator=(const TeamSprite& other);

        void add(CharacterSprite* c);
        void remove(CharacterSprite* c);

    private:
        vector <CharacterSprite*> sprites;

};

#endif // TEAMSPRITE_H
