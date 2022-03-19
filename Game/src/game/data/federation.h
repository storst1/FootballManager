#ifndef FEDERATION_H
#define FEDERATION_H

#include "game/data/data_defs.h"

class LEAGUE;
class CUP;
class NATIONAL_TEAM;

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
