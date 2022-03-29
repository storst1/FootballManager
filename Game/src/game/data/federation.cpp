#include "federation.h"
#include "league.h"
#include "team.h"
#include "cup.h"

FEDERATION::FEDERATION()
{

}

FEDERATION::FEDERATION(int _id, QString _name, int _countryId, QList<LEAGUE *> leaguesList)
    : fedId(_id), name(_name), countryId(_countryId), leagues(leaguesList)
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
