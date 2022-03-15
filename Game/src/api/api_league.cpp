#include "api_league.h"

API_LEAGUE::API_LEAGUE()
{

}

API_LEAGUE::API_LEAGUE(QString id, int fed_id) : id(id), federation(fed_id)
{

}

API_LEAGUE::API_LEAGUE(QString id, QString name, int federation) : id(id), name(name), federation(federation)
{

}

API_LEAGUE::~API_LEAGUE()
{
    //qDeleteAll(clubs);
}

void API_LEAGUE::setName(QString &league_name)
{
    name = league_name;
}

void API_LEAGUE::setName(QString league_name)
{
    name = league_name;
}

/*
void LEAGUE::setClubs(QList<CLUB *> &clubs_list)
{
    clubs = clubs_list;
}
*/

QString API_LEAGUE::getId() const
{
    return id;
}

QString API_LEAGUE::getName() const
{
    return name;
}

int API_LEAGUE::getFed() const
{
    return federation;
}

QString API_LEAGUE::getStrFed() const
{
    return QString::number(getFed());
}
