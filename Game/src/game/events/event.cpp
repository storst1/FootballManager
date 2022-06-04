#include "game/events/event.h"

EVENT::EVENT(DATE date, EventType eventType) : date(date), eventType(eventType)
{

}

EVENT::~EVENT()
{

}

DATE EVENT::getDate() const
{
    return date;
}

EVENT::Order EVENT::getOrder() const
{
    return order;
}

EVENT::EventType EVENT::getEventType() const
{
    return eventType;
}

bool EVENT::operator<(const EVENT &oth_event) const
{
    if(date == oth_event.date){
        return order < oth_event.order;
    }
    return date < oth_event.date;
}

bool EVENT::operator>(const EVENT &oth_event) const
{
    if(date == oth_event.date){
        return order > oth_event.order;
    }
    return date > oth_event.date;
}

bool EVENT::operator==(const EVENT &oth_event) const
{
    return date == oth_event.date;
}

bool EVENT::operator!=(const EVENT &oth_event) const
{
    return !(oth_event == (*this));
}

bool EVENT::CompEvents(const EVENT *first, const EVENT *second)
{
    return (*first) < (*second);
}
