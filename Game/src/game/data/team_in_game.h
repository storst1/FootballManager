#ifndef TEAM_IN_GAME_H
#define TEAM_IN_GAME_H

#include "game/data/data_defs.h"
#include "game/data/player.h"
#include "game/data/team.h"
#include "game/data/match_lineup.h"

class TEAM_IN_GAME
{
public:
    TEAM_IN_GAME();
    ~TEAM_IN_GAME();
private:
    TEAM* team;
    MATCH_LINEUP lineup;
};

#endif // TEAM_IN_GAME_H
