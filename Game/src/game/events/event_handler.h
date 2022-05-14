#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "game/events/event_array.h"
#include "game/time/date.h"

#include <QList>

class EVENT_HANDLER
{
public:
    EVENT_HANDLER();
    EVENT_HANDLER(DATE currentDate);
    ~EVENT_HANDLER();

    DATE getCurDate() const;
    EVENT_ARRAY getAllEventsByDate(DATE date);
    EVENT_ARRAY getAllEventsByDateAndTeam(DATE date, TEAM linkedTeam);
private:
    DATE currentDate;
    EVENT_ARRAY* eventArray;
};

#endif // EVENT_HANDLER_H
