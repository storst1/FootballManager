#include "scheduled_match.h"

SCHEDULED_MATCH::SCHEDULED_MATCH(int id, DATE &gameDate, COMPETITION *comp) : matchId(id), gameDate(gameDate), competition(comp)
{
    determined = false;
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
