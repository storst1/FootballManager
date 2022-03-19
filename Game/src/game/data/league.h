#ifndef LEAGUE_H
#define LEAGUE_H

#include "game/data/data_defs.h"

class CLUB;
class CUP;
class TABLE;

class LEAGUE
{
public:
    LEAGUE();
private:
    QString id;
    QString name;

    QList<CLUB*> clubs;

    CUP* leagueCup; //may be nullptr

    //stats fields
    TABLE* table;
};

#endif // LEAGUE_H
