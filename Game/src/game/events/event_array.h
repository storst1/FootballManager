#ifndef EVENT_ARRAY_H
#define EVENT_ARRAY_H

#include "game/events/event.h"
#include "game/data/team.h"

#include <QVector>

class EVENT_ARRAY
{
public:
    EVENT_ARRAY();
    ~EVENT_ARRAY();

    bool Empty() const;
    size_t Size() const;

    void addEvent(EVENT* event);
    void Continue(DATE tillDate);

    EVENT_ARRAY getAllEventsByDate(DATE date);
    EVENT_ARRAY getAllEventsByDateAndTeam(DATE date, TEAM *linkedTeam);
    EVENT* getMostImportantEvent();
private:
    QVector<EVENT*> events;
};

#endif // EVENT_ARRAY_H
