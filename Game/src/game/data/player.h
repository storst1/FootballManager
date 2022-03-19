#ifndef PLAYER_H
#define PLAYER_H

#include "game/data/data_defs.h"

class PLAYER
{
public:
    PLAYER();
    ~PLAYER();
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
