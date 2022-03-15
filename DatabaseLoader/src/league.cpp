#include "league.h"

LEAGUE::LEAGUE()
{

}

LEAGUE::LEAGUE(QString id, int fed_id) : id(id), federation(fed_id)
{

}

LEAGUE::LEAGUE(QString id, QString name, int federation) : id(id), name(name), federation(federation)
{

}

LEAGUE::~LEAGUE()
{
    //qDeleteAll(clubs);
}

void LEAGUE::setName(QString &league_name)
{
    name = league_name;
}

void LEAGUE::setName(QString league_name)
{
    name = league_name;
}

/*
void LEAGUE::setClubs(QList<CLUB *> &clubs_list)
{
    clubs = clubs_list;
}
*/

QString LEAGUE::getId() const
{
    return id;
}

QString LEAGUE::getName() const
{
    return name;
}

int LEAGUE::getFed() const
{
    return federation;
}

QString LEAGUE::getStrFed() const
{
    return QString::number(getFed());
}
