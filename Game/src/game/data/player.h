#ifndef PLAYER_H
#define PLAYER_H

#include "game/data/data_defs.h"

class PLAYER
{
public:
    PLAYER();
    ~PLAYER();

    int getId();
    QString getName();
    int8_t getAge();
    float getSkill();
    FEDERATION* getFF();
    FEDERATION* getSF();
    PLAYER_POSITION* getPos();
    CLUB* getClub();
private:
    int id;
    QString name;
    int8_t age;
    float skill;
    FEDERATION* FF;
    FEDERATION* SF;
    PLAYER_POSITION* pos;
    CLUB* club;
};

#endif // PLAYER_H
