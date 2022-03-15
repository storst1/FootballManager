#include "club.h"

CLUB::CLUB()
{

}

CLUB::CLUB(int id) : id(id)
{

}

CLUB::CLUB(int id, QString name) : id(id), name(name)
{

}

CLUB::CLUB(int id, QString name, QString league_id) : id(id), name(name), league_id(league_id)
{

}

CLUB::~CLUB()
{
    //qDeleteAll(players);
}

void CLUB::setLeagueId(QString leagueId)
{
    league_id = leagueId;
}

void CLUB::setName(QString club_name)
{
    name = club_name;
}

int CLUB::getId() const
{
    return id;
}

QString CLUB::getStrId() const
{
    return QString::number(getId());
}

QString CLUB::getName() const
{
    return name;
}

QString CLUB::getLeagueId() const
{
    return league_id;
}

/*
void CLUB::setPlayers(QList<PLAYER *> playerList)
{
    players = playerList;
}
*/
