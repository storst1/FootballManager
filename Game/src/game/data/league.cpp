#include "game/data/league.h"
#include "game/data/cup.h"
#include "game/data/team.h"
#include "game/data/table.h"

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
