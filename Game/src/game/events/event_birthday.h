#ifndef EVENT_BIRTHDAY_H
#define EVENT_BIRTHDAY_H

#include "game/events/event.h"
#include "game/data/player.h"

class EVENT_BIRTHDAY : public EVENT
{
public:
    EVENT_BIRTHDAY(DATE date, PLAYER* birthdayPlayer);
    ~EVENT_BIRTHDAY() override = default;

    void Execute() override;
private:
    PLAYER* player;
};

#endif // EVENT_BIRTHDAY_H
