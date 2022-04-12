#ifndef EVENT_H
#define EVENT_H

#include "game/time/date.h"

class EVENT
{
public:
    EVENT(DATE& date);
    virtual ~EVENT() = default;

    virtual void Execute();

    bool operator<(const EVENT& oth_event) const;
protected:
    enum Order{ Morning, Day, Evening };
private:
    DATE date;
    Order order;
};

#endif // EVENT_H
