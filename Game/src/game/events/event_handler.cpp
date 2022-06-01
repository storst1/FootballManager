#include "game/events/event_handler.h"

EVENT_HANDLER::EVENT_HANDLER()
{
    eventArray = new EVENT_ARRAY();
}

EVENT_HANDLER::EVENT_HANDLER(DATE currentDate) : currentDate(currentDate)
{
    eventArray = new EVENT_ARRAY();
}

EVENT_HANDLER::~EVENT_HANDLER()
{
    delete eventArray;
}

DATE EVENT_HANDLER::getCurDate() const
{
    return currentDate;
}

EVENT_ARRAY EVENT_HANDLER::getAllEventsByDate(DATE date)
{
    return eventArray->getAllEventsByDate(date);
}

EVENT_ARRAY EVENT_HANDLER::getAllEventsByDateAndTeam(DATE date, TEAM* linkedTeam)
{
    return eventArray->getAllEventsByDateAndTeam(date, linkedTeam);
}

void EVENT_HANDLER::NextDay()
{
    currentDate = currentDate.NextDay();
}

void EVENT_HANDLER::AddEvent(EVENT *event)
{
    eventArray->addEvent(event);
}

EVENT *EVENT_HANDLER::getMostImportantEvent(EVENT_ARRAY &eventArr)
{
    return eventArr.getMostImportantEvent();
}
