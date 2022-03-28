#include "federation.h"
#include "league.h"
#include "team.h"
#include "cup.h"

FEDERATION::FEDERATION()
{

}

FEDERATION::~FEDERATION()
{
    qDeleteAll(leagues);
    delete nationalTeam;
}

int FEDERATION::getId()
{
    return fedId;
}

QString FEDERATION::getName()
{
    return name;
}

QList<LEAGUE *> FEDERATION::getLeagues()
{
    return leagues;
}
