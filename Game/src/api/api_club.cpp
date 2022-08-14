#include "api/api_club.h"

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

int API_CLUB::getPrestige() const
{
    return prestige;
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

//Budget is equals 1/4 of the total transfer value of the club
void API_CLUB::countBudget()
{
    budget = totalTV / 4;
}

//Binds prestige value to the @prestige property of the class
void API_CLUB::countPrestige()
{
    prestige = API_CLUB::switchTVtoPrestige(totalTV);
}

//Calculates prestige of the club based on the total transfer value of the club
int API_CLUB::switchTVtoPrestige(const int TV)
{
    const int hundred_mil = 1e8f;
    float fTV = float(TV);
    if(fTV >= 7 * hundred_mil) return 10;           // >=700 000 000
    else if(fTV >= 5 * hundred_mil) return 9;       // 500 000 000 - 699 999 999
    else if(fTV >= 3.2 * hundred_mil) return 8;     // 320 000 000 - 499 999 999
    else if(fTV >= 2.5 * hundred_mil) return 7;     // 250 000 000 - 319 999 999
    else if(fTV >= 1.9 * hundred_mil) return 6;     // 190 000 000 - 249 999 999
    else if(fTV >= 1.2 * hundred_mil) return 5;     // 120 000 000 - 189 999 999
    else if(fTV >= 0.65 * hundred_mil) return 4;    // 65 000 000 - 119 999 999
    else if(fTV >= 0.4 * hundred_mil) return 3;     // 40 000 000 - 64 999 999
    else if(fTV >= 0.2 * hundred_mil) return 2;     // 20 000 000 - 39 999 999
    return 1;                                       // <20 000 000
}
