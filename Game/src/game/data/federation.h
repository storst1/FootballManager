#pragma once
#ifndef FEDERATION_H
#define FEDERATION_H

#include "game/data/league.h"
#include "game/data/national_team.h"

#include <QList>

class FEDERATION
{
public:
    FEDERATION();
private:
    int fedId;
    QString name;

    int leaguesTiers;
    QList<LEAGUE*> leagues;

    NATIONAL_TEAM* nationalTeam;
};

#endif // FEDERATION_H
