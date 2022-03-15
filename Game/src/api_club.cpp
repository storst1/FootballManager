#include "api_club.h"

API_CLUB::API_CLUB()
{

}

API_CLUB::API_CLUB(int id) : id(id)
{

}

API_CLUB::API_CLUB(int id, QString name) : id(id), name(name)
{

}

API_CLUB::API_CLUB(int id, QString name, QString league_id) : id(id), name(name), league_id(league_id)
{

}

API_CLUB::~API_CLUB()
{
    //qDeleteAll(players);
}

void API_CLUB::setLeagueId(QString leagueId)
{
    league_id = leagueId;
}

void API_CLUB::setName(QString club_name)
{
    name = club_name;
}

int API_CLUB::getId() const
{
    return id;
}

QString API_CLUB::getStrId() const
{
    return QString::number(getId());
}

QString API_CLUB::getName() const
{
    return name;
}

QString API_CLUB::getLeagueId() const
{
    return league_id;
}

/*
void CLUB::setPlayers(QList<PLAYER *> playerList)
{
    players = playerList;
}
*/
