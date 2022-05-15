#ifndef EVENT_H
#define EVENT_H

#include "game/time/date.h"
#include "game/data/team.h"

#include <QPainter>

class EVENT
{
public:
    enum Order{ Unordered, Morning, Day, Evening };
    enum EventType { Birthday, Game };

    EVENT(DATE& date);
    virtual ~EVENT();

    virtual void Execute() = 0;
    virtual bool IsLinkedToTeam(TEAM team) const = 0;
    virtual void paintEvent(QPainter& painter, int row) = 0;

    DATE getDate() const;
    Order getOrder() const;
    EventType getEventType() const;

    bool operator<(const EVENT& oth_event) const;
protected:
    DATE date;
    Order order = Unordered;
    EventType eventType;
};

#endif // EVENT_H
