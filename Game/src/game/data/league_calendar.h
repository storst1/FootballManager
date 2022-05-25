#ifndef LEAGUE_CALENDAR_H
#define LEAGUE_CALENDAR_H

#include "game/data/calendar.h"

class LEAGUE_CALENDAR : public CALENDAR
{
public:
    LEAGUE_CALENDAR(QList<TEAM*>& allTeams);
    LEAGUE_CALENDAR(QList<TEAM*>& allTeams, QList<int>& startingStage);
    LEAGUE_CALENDAR(QList<QPair<TEAM*, int>>& infoList);
    ~LEAGUE_CALENDAR() = default;

    void Generate(int start_year) override;
    void Clear() override;
    QList<SCHEDULED_MATCH*> GetTour(int id) const override;
    QList<SCHEDULED_MATCH*> GetTour(const QString& id) const override;
    QString GetTourName(int id) const override;
private:
    QList<QList<SCHEDULED_MATCH*>> calendar;
};

#endif // LEAGUE_CALENDAR_H
