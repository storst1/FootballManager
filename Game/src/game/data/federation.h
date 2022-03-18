#ifndef FEDERATION_H
#define FEDERATION_H

#include "data_defs.h"
#include "game/data/confederation.h"
#include "game/data/league.h"
#include "game/data/national_team.h"

class FEDERATION
{
public:
    FEDERATION();
    ~FEDERATION();
private:
    int fedId;
    QString name;

    int leaguesTiers;
    QList<LEAGUE*> leagues;

    CUP* natCup;

    NATIONAL_TEAM* nationalTeam;
};

#endif // FEDERATION_H
