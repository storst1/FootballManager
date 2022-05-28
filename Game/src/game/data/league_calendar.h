#ifndef LEAGUE_CALENDAR_H
#define LEAGUE_CALENDAR_H

#include "game/data/calendar.h"
#include "game/time/date.h"

class LEAGUE_CALENDAR : public CALENDAR
{
public:
    LEAGUE_CALENDAR(QVector<TEAM*>& allTeams);
    LEAGUE_CALENDAR(QVector<TEAM*>& allTeams, QVector<int>& startingStage);
    LEAGUE_CALENDAR(QVector<QPair<TEAM*, int>>& infoList);
    ~LEAGUE_CALENDAR() = default;

    void Generate(int start_year) override;
    void Clear() override;
    QVector<SCHEDULED_MATCH*> GetTour(int id) const override;
    QVector<SCHEDULED_MATCH*> GetTour(const QString& id) const override;
    QString GetTourName(int id) const override;
private:
    QVector<QVector<SCHEDULED_MATCH*>> calendar;
};

#endif // LEAGUE_CALENDAR_H
