#include "Team.h"

Team* Team::instance = 0;

Team::Team()
{
    //ctor
}

Team* Team::getInstance()
{
    if(instance==0)
        instance = new Team();
    return instance;
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

void Team::remove(Character* c)
{
    for(unsigned int i=0; i< team.size(); i++){
        if(*team[i] == c)
        {
            team.erase(team.begin()+i);
            delete c;
            return;
        }

    }
}

void Team::setTeam(const Character* a, const Character* b)
{
    for(unsigned int i=0; i<team.size(); i++)
    {
        if(*team[i] == a)
        {
            team[i] = b->clone();
            delete a;
            return;
        }
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
