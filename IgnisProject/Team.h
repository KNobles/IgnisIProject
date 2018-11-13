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
        Team();
        static Team* instance;


    public:
        Team(const Team& other) = delete;
        Team& operator=(const Team& other) = delete;

        static Team* getInstance();
        bool contains(const Character* c)const;
        void add(Character* c);
        void remove(Character* c);
        void setTeam(const Character* a, const Character* b);
        vector<Character*> getTeam()const;

        string str()const;

    protected:


};

#endif // TEAM_H
