#include "game/events/event_array.h"

EVENT_ARRAY::EVENT_ARRAY()
{

}

EVENT_ARRAY::~EVENT_ARRAY()
{
    //qDeleteAll(events);
}

bool EVENT_ARRAY::Empty() const
{
    return Size() == 0;
}

size_t EVENT_ARRAY::Size() const
{
    return events.size();
}

void EVENT_ARRAY::addEvent(EVENT *event)
{
    /*
    qDebug() << "AddEvent() called with event of date: " << QString(event->getDate());
    if(events.empty()){
        qDebug() << "Array was empty, so new_event added to the back";
        events.push_back(event);
        return;
    }
    int i = 0;
    while(i < events.size()){
        if(event > events[i]){
            break;
        }
        qDebug() << QString(event->getDate()) << " < " << QString(events[i]->getDate()) << " , continuening";
        ++i;
    }
    qDebug() << "Inserting at idx = " << i << " of " << events.size();
    events.insert(i, event);
    */

    auto placeIter = std::lower_bound(events.begin(), events.end(), event, EVENT::CompEvents);
    //qDebug() << "Before insert: " << events.cbegin() << " " << events.cend();
    events.insert(placeIter - events.begin(), event);
    //qDebug() << "After insert: " << events.cbegin() << " " << events.cend() << " , placeIter = " << placeIter;
    /*
    Needs changes to use
    if(events.size() > 2 && placeIter != events.end() - 1 && placeIter != events.begin()){
        qDebug() << QString((*(placeIter - 1))->getDate())
                 << " < " << QString((*placeIter)->getDate())
                 << " < " << QString((*(placeIter + 1))->getDate());

        qDebug() << (*(placeIter - 1))->getDate().getRawDate()
                 << " < " << (*placeIter)->getDate().getRawDate()
                 << " < " << (*(placeIter + 1))->getDate().getRawDate();
    }
    */
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
    /*
    for(int i = 0; i < events.size(); ++i){
        qDebug() << QString(events[i]->getDate());
    }
    */


    EVENT_ARRAY arrayToRet;
    for(int i = 0; i < events.size(); ++i){
        if(events[i]->getDate() < date){
            //qDebug() << QString(date) << " > " << QString(events[i]->getDate());
            continue;
        }
        else if(events[i]->getDate() > date){
            //qDebug() << QString(date) << " < " << QString(events[i]->getDate());
            break;
        }

        //qDebug() << QString(date) << " == " << QString(events[i]->getDate());

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
