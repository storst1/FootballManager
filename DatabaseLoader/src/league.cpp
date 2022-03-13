#include "league.h"

LEAGUE::LEAGUE()
{

}

LEAGUE::LEAGUE(QString id, int fed_id) : id(id), federation(fed_id)
{

}

LEAGUE::LEAGUE(QString id, QString name, int federation, QList<CLUB *> clubs) : id(id), name(name), federation(federation), clubs(clubs)
{

}

LEAGUE::~LEAGUE()
{
    qDeleteAll(clubs);
}

void LEAGUE::setName(QString &league_name)
{
    name = league_name;
}

void LEAGUE::setName(QString league_name)
{
    name = league_name;
}

void LEAGUE::setClubs(QList<CLUB *> &clubs_list)
{
    clubs = clubs_list;
}
