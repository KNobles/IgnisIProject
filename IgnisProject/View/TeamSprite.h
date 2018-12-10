#ifndef TEAMSPRITE_H
#define TEAMSPRITE_H

#include <SFML/Graphics.hpp>
#include "CharacterSprite.h"
#include "Team.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using std::vector;
using std::string;
using std::stringstream;
using std::cout;
using std::endl;

class TeamSprite
{
    public:
        TeamSprite();
        TeamSprite(const Team& t);
        virtual ~TeamSprite();
        TeamSprite(const TeamSprite& other);
        TeamSprite& operator=(const TeamSprite& other);

        void add(CharacterSprite* c);
        void remove(CharacterSprite* c);
        vector <CharacterSprite*> getTeam() const;

    private:
        vector <CharacterSprite*> sprites;

};

#endif // TEAMSPRITE_H
