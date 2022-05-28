#include "game/data/federation.h"
#include "game/data/league.h"
#include "game/data/team.h"
#include "game/data/cup.h"

FEDERATION::FEDERATION()
{

}

FEDERATION::FEDERATION(int _id, QString _name, int _countryId, QVector<LEAGUE *> leaguesList)
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

QVector<LEAGUE *> FEDERATION::getLeagues()
{
    return leagues;
}

QPixmap *FEDERATION::getFlag() const
{
    return flagPixmap;
}

void FEDERATION::setLeagues(QVector<LEAGUE *> leaguesList)
{
    leagues = leaguesList;
}

void FEDERATION::setFlag(QPixmap *flag)
{
    flagPixmap = flag;
}

bool FEDERATION::CompTwoFedsByName(const FEDERATION *f1, const FEDERATION *f2)
{
    return f1->getName() < f2->getName();
}
