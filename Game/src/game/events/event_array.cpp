#include "game/events/event_array.h"

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

void EVENT_ARRAY::Continue(DATE tillDate)
{
    while(!events.empty() && events.front()->getDate() < tillDate){
        events.front()->Execute();
    }
}
