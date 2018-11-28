#include "Team.h"

Team::Team()
{

}

Team::~Team(){
    for(unsigned int i=0; i<team.size(); i++)
    {
        delete team[i];
    }
    team.clear();
}

Team::Team(const Team& other)
{
    for(unsigned int i=0; i<other.team.size(); i++)
    {
        Character* c = other.team[i]->clone();
        team.push_back(c);
    }
}

Team& Team::operator=(const Team& rhs)
{
    for(unsigned int i=0; i<team.size(); i++)
    {
        delete team[i];
    }
    team.clear();

    for(unsigned int i=0; i<rhs.team.size(); i++)
    {
        Character* c = rhs.team[i]->clone();
        team.push_back(c);
    }
}

bool Team::contains(const Character* c)const
{
    for(unsigned int i=0; i<team.size(); i++)
    {
        if(*team[i] == c)
            return true;
    }
    return false;
}

void Team::add(Character* c)
{
    if(!contains(c))
        team.push_back(c->clone());
}
//A modifier
void Team::remove(Character* c)
{
    if(contains(c)){
        team.erase(team.begin()+indexOf(c));
        delete c;
    }
}

Character* Team::get(const int index)const
{
    return team[index];
}

int Team::indexOf(const Character* c)const
{
    if(contains(c))
    {
        for(unsigned int i=0; i < team.size(); i++)
        {
            if(*team[i] == c)
            {
                return i;
            }
        }
    }
    return -1;

}

void Team::setTeam(const Character* a, const Character* b)
{
    int index = indexOf(a);
    if(index >= 0)
    {
        team[index] = b->clone();
        delete a;
        return;
    }
}

vector<Character*> Team::getTeam()const
{
    vector<Character*> result;
    for(unsigned int i=0; i<team.size(); i++)
        result.push_back(team[i]->clone());
    return result;
}

string Team::str()const
{
    stringstream result;
    for(unsigned int i=0; i<team.size(); i++)
        result << team[i]->str() << endl;
    return result.str();
}
