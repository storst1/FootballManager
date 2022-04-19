#include "game/data/league.h"
#include "game/data/cup.h"
#include "game/data/team.h"
#include "game/data/table.h"

LEAGUE::LEAGUE()
{

}

LEAGUE::~LEAGUE()
{
    delete table;
    delete leagueCup;
    qDeleteAll(clubs);
}

QString LEAGUE::getId() const
{
    return id;
}

QString LEAGUE::getName() const
{
    return name;
}

QList<CLUB *> LEAGUE::getClubs() const
{
    return clubs;
}

int LEAGUE::getTier() const
{
    return tier;
}

FEDERATION *LEAGUE::getFederation() const
{
    return fed;
}

void LEAGUE::setName(QString &_name)
{
    name = _name;
}

void LEAGUE::setTier(int t)
{
    tier = t;
}

void LEAGUE::setId(QString &_id)
{
    id = _id;
}

void LEAGUE::setClubList(QList<CLUB *> clubList)
{
    clubs = clubList;
}

void LEAGUE::setFederation(FEDERATION *_fed)
{
    fed = _fed;
}
