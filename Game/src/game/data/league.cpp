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

QString LEAGUE::getId()
{
    return id;
}

QString LEAGUE::getName()
{
    return name;
}

QList<CLUB *> LEAGUE::getClubs()
{
    return clubs;
}
