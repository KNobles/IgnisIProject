#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Character.h"

using std::string;
using std::stringstream;
using std::cout;
using std::endl;
using std::vector;

class Team
{

    private:
        vector<Character*> team;


    public:
        Team();
        Team(const Team& other);
        Team& operator=(const Team& other);
        virtual ~Team();

        bool contains(const Character* c)const;
        void add(Character* c);
        void remove(Character* c);
        Character* get(const int index)const;
        int indexOf(const Character* c)const;
        void setTeam(const Character* a, const Character* b);
        vector<Character*> getTeam()const;

        string str()const;

    protected:


};

#endif // TEAM_H
