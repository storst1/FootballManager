#ifndef EVENT_H
#define EVENT_H

#include "game/time/date.h"
#include "game/data/team.h"

class EVENT
{
public:
    EVENT(DATE& date);
    virtual ~EVENT() = default;

    virtual void Execute() = 0;
    virtual bool IsLinkedToTeam(TEAM team) const;

    DATE getDate() const;

    bool operator<(const EVENT& oth_event) const;

    enum Order{ Morning, Day, Evening };
private:
    DATE date;
    Order order;
};

#endif // EVENT_H
