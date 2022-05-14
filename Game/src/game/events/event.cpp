#include "game/events/event.h"

EVENT::EVENT(DATE& date) : date(date)
{

}

DATE EVENT::getDate() const
{
    return date;
}

bool EVENT::operator<(const EVENT &oth_event) const
{
    if(date == oth_event.date){
        return order < oth_event.order;
    }
    return date < oth_event.date;
}
