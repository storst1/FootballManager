#include "game/data/competition.h"
#include "game/data/calendar.h"
#include "game/data/league_calendar.h"

COMPETITION::COMPETITION()
{

}

FEDERATION *COMPETITION::getFederation() const
{
    return fed;
}

CALENDAR *COMPETITION::getCalendar()
{
    return calendar;
}

void COMPETITION::setName(QString &_name)
{
    name = _name;
}

void COMPETITION::setId(QString &_id)
{
    id = _id;
}

void COMPETITION::setTeamList(QVector<TEAM *> clubList)
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

QVector<TEAM *> COMPETITION::getTeams() const
{
    return clubs;
}
