#include "game/events/event_birthday.h"

EVENT_BIRTHDAY::EVENT_BIRTHDAY(DATE date, PLAYER* birthdayPlayer) :
    EVENT(date), player(birthdayPlayer)
{
}

void EVENT_BIRTHDAY::Execute()
{
    player->addOneYearToAge();
    //TO DO: perhaps add morale boost here or smth similar
}

bool EVENT_BIRTHDAY::IsLinkedToTeam(TEAM team) const
{
    if(player->getClub()->getId() == team.getId()){
        return true;
    }
    return false;
}
