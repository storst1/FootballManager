#ifndef SCHEDULED_MATCH_H
#define SCHEDULED_MATCH_H

#include "game/data/data_defs.h"
#include "game/data/team.h"
#include "game/time/date.h"
#include "game/data/competition.h"

class SCHEDULED_MATCH
{
public:
    SCHEDULED_MATCH(int id, DATE& gameDate, COMPETITION* comp);
    SCHEDULED_MATCH(int id, DATE& gameDate, COMPETITION* comp, TEAM* HT, TEAM* AT);
    ~SCHEDULED_MATCH();

    bool IsDetermined() const noexcept;
    void Determine(TEAM* HT, TEAM* AT);
private:
    int matchId; //has to be unique inside competition
    DATE gameDate;
    COMPETITION* competition;
    TEAM* homeTeam = nullptr;
    TEAM* awayTeam = nullptr;
    bool determined = true;
};

#endif // SCHEDULED_MATCH_H
