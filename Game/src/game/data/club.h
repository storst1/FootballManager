#pragma once
#ifndef CLUB_H
#define CLUB_H

//#include "game/data/team.h"
#include "game/data/data_defs.h"
#include "game/data/team.h"
#include "game/data/stadium.h"

class CLUB : public TEAM
{
public:
    CLUB();
    ~CLUB() = default;

private:
    int TV;
    int budget;
    STADIUM* stadium;
};

#endif // CLUB_H
