#include "game/events/event.h"

EVENT::EVENT(DATE& date) : date(date)
{

}

void EVENT::Execute()
{
    //Calling Execute() on the event-base class does nothing
}

bool EVENT::operator<(const EVENT &oth_event) const
{
    if(date == oth_event.date){
        return order < oth_event.order;
    }
    return date < oth_event.date;
}
