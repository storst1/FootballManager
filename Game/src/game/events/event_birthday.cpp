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
