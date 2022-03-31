#include "federation.h"
#include "league.h"
#include "team.h"
#include "cup.h"

FEDERATION::FEDERATION()
{

}

FEDERATION::FEDERATION(int _id, QString _name, int _countryId, QList<LEAGUE *> leaguesList)
    : fedId(_id), countryId(_countryId), name(_name), leagues(leaguesList)
{

}

FEDERATION::FEDERATION(int _id, QString _name, int _countryId)
    : fedId(_id), countryId(_countryId), name(_name)
{

}

FEDERATION::~FEDERATION()
{
    qDeleteAll(leagues);
    delete nationalTeam;
}

int FEDERATION::getId() const
{
    return fedId;
}

QString FEDERATION::getName() const
{
    return name;
}

QList<LEAGUE *> FEDERATION::getLeagues()
{
    return leagues;
}

void FEDERATION::setLeagues(QList<LEAGUE *> leaguesList)
{
    leagues = leaguesList;
}
