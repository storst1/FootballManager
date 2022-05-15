#ifndef MATCH_H
#define MATCH_H

#include "game/data/team_in_game.h"

class MATCH
{
public:
    MATCH();
    ~MATCH();
private:
    TEAM_IN_GAME homeTeam;
    TEAM_IN_GAME awayTeam;
};

#endif // MATCH_H
