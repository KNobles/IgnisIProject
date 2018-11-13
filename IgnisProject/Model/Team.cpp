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
    team.erase(team.begin()+indexOf(c));
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
