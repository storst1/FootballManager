#pragma once
#ifndef LEAGUE_H
#define LEAGUE_H

#include "game/data/data_defs.h"
#include "game/data/club.h"

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
