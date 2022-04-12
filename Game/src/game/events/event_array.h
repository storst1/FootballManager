#ifndef EVENT_ARRAY_H
#define EVENT_ARRAY_H

#include "game/events/event.h"

#include <QList>

class EVENT_ARRAY
{
public:
    EVENT_ARRAY();

    void addEvent(EVENT* event);
private:
    QList<EVENT*> events;
};

#endif // EVENT_ARRAY_H
