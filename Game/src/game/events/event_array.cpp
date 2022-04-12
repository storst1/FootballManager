#include "event_array.h"

EVENT_ARRAY::EVENT_ARRAY()
{

}

EVENT_ARRAY::~EVENT_ARRAY()
{
    qDeleteAll(events);
}

void EVENT_ARRAY::addEvent(EVENT *event)
{
    events.push_back(event);
}
