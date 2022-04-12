#include "event_array.h"

EVENT_ARRAY::EVENT_ARRAY()
{

}

void EVENT_ARRAY::addEvent(EVENT *event)
{
    events.push_back(event);
}
