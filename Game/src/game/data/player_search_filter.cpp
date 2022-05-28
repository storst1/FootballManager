#include "game/data/player_search_filter.h"

PLAYER_SEARCH_FILTER::PLAYER_SEARCH_FILTER()
{

}

void PLAYER_SEARCH_FILTER::setNations(QVector<FEDERATION *> nationsList)
{
    nations = nationsList;
}

void PLAYER_SEARCH_FILTER::setSecondNations(QVector<FEDERATION *> secondNationsList)
{
    secondNations = secondNationsList;
}

void PLAYER_SEARCH_FILTER::setName(QString _name)
{
    name = _name;
}

void PLAYER_SEARCH_FILTER::setTeam(QString _team)
{
    team = _team;
}

void PLAYER_SEARCH_FILTER::setLeagues(QVector<LEAGUE *> _leagues)
{
    leagues = _leagues;
}

void PLAYER_SEARCH_FILTER::setMinAge(int min)
{
    minAge = min;
}

void PLAYER_SEARCH_FILTER::setMaxAge(int max)
{
    maxAge = max;
}

void PLAYER_SEARCH_FILTER::setAgeBorders(int min, int max)
{
    setMinAge(min);
    setMaxAge(max);
}

void PLAYER_SEARCH_FILTER::setPos(QVector<int> _positions)
{
    positions = _positions;
}

void PLAYER_SEARCH_FILTER::setSecondPos(QVector<int> _positions)
{
    secondPositions = _positions;
}

void PLAYER_SEARCH_FILTER::setMinTV(int min)
{
    minTV = min;
}

void PLAYER_SEARCH_FILTER::setMaxTV(int max)
{
    maxTV = max;
}

void PLAYER_SEARCH_FILTER::setTVBorders(int min, int max)
{
    setMinTV(min);
    setMaxTV(max);
}

void PLAYER_SEARCH_FILTER::setMinSkill(int min)
{
    minSkill = min;
}

void PLAYER_SEARCH_FILTER::setMaxSkill(int max)
{
    maxSkill = max;
}

void PLAYER_SEARCH_FILTER::setSkillBorders(int min, int max)
{
    setMinSkill(min);
    setMaxSkill(max);
}

QVector<FEDERATION *> &PLAYER_SEARCH_FILTER::getNations()
{
    return nations;
}

QVector<FEDERATION *> &PLAYER_SEARCH_FILTER::getSecondNations()
{
    return secondNations;
}

QString &PLAYER_SEARCH_FILTER::getName()
{
    return name;
}

QString &PLAYER_SEARCH_FILTER::getTeam()
{
    return team;
}

QVector<LEAGUE *> &PLAYER_SEARCH_FILTER::getLeagues()
{
    return leagues;
}

int PLAYER_SEARCH_FILTER::getMinAge() const
{
    return minAge;
}

int PLAYER_SEARCH_FILTER::getMaxAge() const
{
    return maxAge;
}

QVector<int> &PLAYER_SEARCH_FILTER::getPositions()
{
    return positions;
}

QVector<int> &PLAYER_SEARCH_FILTER::getSecondPositions()
{
    return secondPositions;
}

int PLAYER_SEARCH_FILTER::getMinTV() const
{
    return minTV;
}

int PLAYER_SEARCH_FILTER::getMaxTV() const
{
    return maxTV;
}

int PLAYER_SEARCH_FILTER::getMinSkill() const
{
    return minSkill;
}

int PLAYER_SEARCH_FILTER::getMaxSkill() const
{
    return maxSkill;
}
