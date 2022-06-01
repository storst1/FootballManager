#include "game/events/event_array.h"

EVENT_ARRAY::EVENT_ARRAY()
{

}

EVENT_ARRAY::~EVENT_ARRAY()
{
    //qDeleteAll(events);
}

void EVENT_ARRAY::addEvent(EVENT *event)
{
    if(events.empty()){
        events.push_back(event);
        return;
    }
    int i = 0;
    while(i < events.size() && event > events[i]){
        ++i;
    }
    events.insert(i, event);
}

void EVENT_ARRAY::Continue(DATE tillDate)
{
    while(!events.empty() && events.front()->getDate() < tillDate){
        events.front()->Execute();
    }
}

EVENT_ARRAY EVENT_ARRAY::getAllEventsByDate(DATE date)
{
    EVENT_ARRAY arrayToRet;
    for(int i = 0; i < events.size(); ++i){
        if(events[i]->getDate() < date){
            continue;
        }
        else if(events[i]->getDate() > date){
            break;
        }
        arrayToRet.addEvent(events[i]);
    }
    return arrayToRet;
}

EVENT_ARRAY EVENT_ARRAY::getAllEventsByDateAndTeam(DATE date, TEAM* linkedTeam)
{
    EVENT_ARRAY arrayToRet;
    for(int i = 0; i < events.size(); ++i){
        if(events[i]->getDate() < date){
            continue;
        }
        else if(events[i]->getDate() > date){
            break;
        }

        if(events[i]->IsLinkedToTeam(linkedTeam)){
            arrayToRet.addEvent(events[i]);
        }
    }
    return arrayToRet;
}

EVENT *EVENT_ARRAY::getMostImportantEvent()
{
    if(events.empty()){
        return nullptr;
    }
    EVENT* mostImpEvent = events[0];
    for(int i = 1; i < (int)events.size(); ++i){
        if(mostImpEvent->getEventType() < events[i]->getEventType()){
            mostImpEvent = events[i];
        }
    }
    return mostImpEvent;
}
