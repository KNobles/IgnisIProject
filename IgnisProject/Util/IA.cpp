#include "IA.h"

IA::IA(TeamSprite ally)
{
    teamAlly = ally;
}

IA::~IA()
{
    //dtor
}

IA::IA(const IA& other)
{
    //copy ctor
}

IA& IA::operator=(const IA& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
void IA::moveIA(){
    int step=this->ch.getCharacter()->getMovement();
    int range=this->ch.getCharacter()->getWeapon()->getRange();
    CharacterSprite tmpCh =chooseTargetIA();
    int tmpDestiX = tmpCh.getPosition().x;
    int tmpDestiY = tmpCh.getPosition().y;
    for (int i=0;i<=step;i++){
        int pass =0;
        if ((ch.getPosition().x>tmpDestiX)&&pass==0){
                if(tmpDestiX-ch.getPosition().x==range){
                    this->attackIA();
                    i=step;
                }
            ch.setPosition(ch.getPosition().x-1,ch.getPosition().y);
            pass=1;
        }
        if ((ch.getPosition().x<tmpDestiX)&&pass==0){
                if(ch.getPosition().x-tmpDestiX==range){
                    this->attackIA();
                    i=step;
                }
            ch.setPosition(ch.getPosition().x+1,ch.getPosition().y);
            pass=1;
        }
        if ((ch.getPosition().y>tmpDestiY)&&pass==0){
            if(tmpDestiY-ch.getPosition().y==range){
                    this->attackIA();
                    i=step;
                }
            ch.setPosition(ch.getPosition().x,ch.getPosition().y-1);
            pass=1;
        }
        if ((ch.getPosition().y<tmpDestiY)&&pass==0){
            if(ch.getPosition().y-tmpDestiY==range){
                    this->attackIA();
                    i=step;
                }
            ch.setPosition(ch.getPosition().x,ch.getPosition().y+1);
            pass=1;
        }
    }
}
void IA::attackIA(){
    Character* tmpCh;
    tmpCh=chooseTargetIA().getCharacter();
    combat(*this->ch.getCharacter(), *tmpCh, tmpCh->getWeapon()->getRange());

}
CharacterSprite IA::chooseTargetIA(){
    int tmpxMin=99;
    int tmpyMin=99;
    CharacterSprite tmpCh;
    vector<CharacterSprite*> teamAlly = this->teamAlly.getTeam();
    for(ally : teamAlly)
    {
        int tmpx=ally->getPosition().x-this->ch.getPosition().x;
        int tmpy=ally->getPosition().y-this->ch.getPosition().y;
            if((tmpxMin<tmpx)&&(tmpyMin<tmpy))
            {
                tmpxMin=tmpx;
                tmpyMin=tmpy;
            }
    }
    for(ally : teamAlly)
    {
        int tmpx=ally->getPosition().x;
        int tmpy=ally->getPosition().y;
        if((tmpxMin==tmpx)&&(tmpyMin==tmpy))
        {
            tmpCh=ch;
        }

     }
     return tmpCh;
}
