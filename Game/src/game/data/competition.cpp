#include "game/data/competition.h"

COMPETITION::COMPETITION()
{

}

FEDERATION *COMPETITION::getFederation() const
{
    return fed;
}

void COMPETITION::setName(QString &_name)
{
    name = _name;
}

void COMPETITION::setId(QString &_id)
{
    id = _id;
}

void COMPETITION::setClubList(QVector<CLUB *> clubList)
{
    clubs = clubList;
}

void COMPETITION::setFederation(FEDERATION *_fed)
{
    fed = _fed;
}

QString COMPETITION::getId() const
{
    return id;
}

QString COMPETITION::getName() const
{
    return name;
}

QVector<CLUB *> COMPETITION::getClubs() const
{
    return clubs;
}
