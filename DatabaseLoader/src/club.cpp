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

CLUB::~CLUB()
{
    qDeleteAll(players);
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

void CLUB::setPlayers(QList<PLAYER *> playerList)
{
    players = playerList;
}
