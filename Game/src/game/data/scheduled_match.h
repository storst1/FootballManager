#ifndef SCHEDULED_MATCH_H
#define SCHEDULED_MATCH_H

#include "game/data/data_defs.h"
#include "game/data/team.h"
#include "game/time/date.h"
#include "game/data/competition.h"

class SCHEDULED_MATCH
{
public:
    SCHEDULED_MATCH();
    ~SCHEDULED_MATCH();
private:
    COMPETITION* competition;
    TEAM* homeTeam;
    TEAM* awayTeam;
    DATE gameDate;
};

#endif // SCHEDULED_MATCH_H
