#include "league.h"
#include "cup.h"
#include "team.h"
#include "table.h"

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

void LEAGUE::setName(QString &_name)
{
    name = _name;
}

void LEAGUE::setTier(int t)
{
    tier = t;
}

void LEAGUE::setClubList(QList<CLUB *> clubList)
{
    clubs = clubList;
}
