#include "game/data/league.h"
#include "game/data/cup.h"
#include "game/data/team.h"
#include "game/data/table.h"
#include "game/data/calendar.h"
#include "game/data/league_calendar.h"

LEAGUE::LEAGUE() : COMPETITION()
{

}

LEAGUE::~LEAGUE()
{
    delete table;
    //delete leagueCup;
    //qDeleteAll(clubs);
}

int LEAGUE::getTier() const
{
    return tier;
}

void LEAGUE::setTier(int t){
    tier = t;
}

void LEAGUE::setupCalendar()
{
    if(!calendar){
        calendar = new LEAGUE_CALENDAR(clubs, this);
    }
}

void LEAGUE::generateCalendar(int year)
{
    calendar->Clear();
    calendar->ClearTeams();
    calendar->SetTeams(clubs);
    calendar->Generate(year);
}
