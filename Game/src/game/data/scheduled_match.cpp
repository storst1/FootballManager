#include "scheduled_match.h"

SCHEDULED_MATCH::SCHEDULED_MATCH(int id, COMPETITION *comp) : matchId(id), competition(comp)
{
    determined = false;
}

SCHEDULED_MATCH::SCHEDULED_MATCH(int id, DATE &gameDate, COMPETITION *comp) : matchId(id), gameDate(gameDate), competition(comp)
{
    determined = false;
}

SCHEDULED_MATCH::SCHEDULED_MATCH(int id, COMPETITION *comp, TEAM *HT, TEAM *AT) :
    matchId(id), competition(comp), homeTeam(HT), awayTeam(AT)
{

}

SCHEDULED_MATCH::SCHEDULED_MATCH(int id, DATE &gameDate, COMPETITION* comp, TEAM *HT, TEAM *AT) :
    matchId(id), gameDate(gameDate), competition(comp), homeTeam(HT), awayTeam(AT)
{

}

SCHEDULED_MATCH::~SCHEDULED_MATCH()
{

}

bool SCHEDULED_MATCH::IsDetermined() const noexcept
{
    return determined;
}

void SCHEDULED_MATCH::Determine(TEAM *HT, TEAM *AT)
{
    determined = true;
    homeTeam = HT;
    awayTeam = AT;
}

void SCHEDULED_MATCH::SetDate(DATE date)
{
    gameDate = date;
}

int SCHEDULED_MATCH::getId() const
{
    return matchId;
}

DATE SCHEDULED_MATCH::getDate() const
{
    return gameDate;
}

COMPETITION *SCHEDULED_MATCH::getComp()
{
    return competition;
}

TEAM *SCHEDULED_MATCH::getHT()
{
    return homeTeam;
}

TEAM *SCHEDULED_MATCH::getAT()
{
    return awayTeam;
}

bool SCHEDULED_MATCH::compTwoSMByDate(const SCHEDULED_MATCH *SM1, const SCHEDULED_MATCH *SM2) noexcept
{
    return SM1->getDate() < SM2->getDate();
}
