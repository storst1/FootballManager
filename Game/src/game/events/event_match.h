#ifndef EVENT_MATCH_H
#define EVENT_MATCH_H

#include "game/events/event.h"
#include "game/data/scheduled_match.h"

class EVENT_MATCH : public EVENT
{
public:
    EVENT_MATCH(SCHEDULED_MATCH* scheduledMatch);
    ~EVENT_MATCH() override = default;

    void Execute() override;
    bool IsLinkedToTeam(TEAM* team) const override;
    void paintEvent(QPainter& painter, int row) override;

private:
    SCHEDULED_MATCH* match;
};

#endif // EVENT_MATCH_H
