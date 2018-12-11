#include "TeamSprite.h"
#include "GameDimens.h"
TeamSprite::TeamSprite(){}

TeamSprite::TeamSprite(const Team& t)
{
    for(unsigned int i=0; i< t.getTeam().size(); i++)
    {
        cout << "on construit un charactersprite" << endl;
        CharacterSprite* c = new CharacterSprite(t.get(i));
        cout << "on ajoute le sprite dans la team" << endl;
        sprites.push_back(c);
        cout << "sprite ajoute" << endl;
    }
}

TeamSprite::~TeamSprite()
{
    for(unsigned int i=0; i< sprites.size(); i++){
        delete sprites[i];
    }
    sprites.clear();
}

TeamSprite::TeamSprite(const TeamSprite& other)
{
    for(unsigned int i=0; i< other.sprites.size(); i++)
    {
        sprites.push_back(new CharacterSprite(*other.sprites[i]));
    }
}

TeamSprite& TeamSprite::operator=(const TeamSprite& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    for(unsigned int i=0; i< sprites.size(); i++){
        delete sprites[i];
    }
    sprites.clear();

    for(unsigned int i=0; i< rhs.sprites.size(); i++)
    {
        sprites.push_back(new CharacterSprite(*rhs.sprites[i]));
    }

    return *this;
}

void TeamSprite::add(CharacterSprite* c)
{

    for(unsigned int i=0; i<sprites.size(); i++)
    {
        if(sprites[i] == c)
        {
            return;
        }
    }
    sprites.push_back(new CharacterSprite(*c));
}

void TeamSprite::remove(CharacterSprite* c)
{
    for(unsigned int i=0; i<sprites.size(); i++)
    {
        if(sprites[i] == c)
        {
            sprites.erase(sprites.begin()+i);
            delete c;
        }
    }

}
vector <CharacterSprite*> TeamSprite::getTeam() const
{
    return sprites;
}
