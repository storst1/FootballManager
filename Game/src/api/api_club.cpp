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

API_CLUB::API_CLUB(int id, QString name, QString league_id, QString sd_name, int sd_cap, int totalTV)
    : id(id), name(name), league_id(league_id), stadName(sd_name), stadCapacity(sd_cap), totalTV(totalTV)
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

QString API_CLUB::getStadName() const
{
    return stadName;
}

int API_CLUB::getStadCapacity() const
{
    return stadCapacity;
}

int API_CLUB::getTV() const
{
    return totalTV;
}

int API_CLUB::getBudget() const
{
    return budget;
}

void API_CLUB::insertAdditionalInfoFromJson(JSON_PARSER_CLUB clubAddInfo)
{
    stadName = clubAddInfo.getStadName();
    stadCapacity = clubAddInfo.getStadCapacity();
}

void API_CLUB::addTV(int playerTV)
{
    totalTV += playerTV;
}

void API_CLUB::setStadName(QString name)
{
    stadName = name;
}

void API_CLUB::setStadCap(int cap)
{
    stadCapacity = cap;
}

void API_CLUB::countBudget()
{
    budget = totalTV / 4;
}
