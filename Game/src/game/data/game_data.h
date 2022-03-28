#ifndef GAME_DATA_H
#define GAME_DATA_H

#include "game/data/data_defs.h"

class GAME_DATA
{
public:
    GAME_DATA();
    ~GAME_DATA();
private:
    FIFA* fifa;
    QList<FEDERATION*> federations;
    QList<LEAGUE*> leagues;
    QList<CLUB*> clubs;
    QList<PLAYER*> players;
};

#endif // GAME_DATA_H
