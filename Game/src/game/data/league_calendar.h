#ifndef LEAGUE_CALENDAR_H
#define LEAGUE_CALENDAR_H

#include "game/data/data_defs.h"
#include "game/data/calendar.h"

class LEAGUE_CALENDAR : public CALENDAR
{
public:
    LEAGUE_CALENDAR(QVector<TEAM*>& allTeams, COMPETITION* comp);
    LEAGUE_CALENDAR(QVector<TEAM*>& allTeams, QVector<int>& startingStage, COMPETITION* comp);
    LEAGUE_CALENDAR(QVector<QPair<TEAM*, int>>& infoList, COMPETITION* comp);
    ~LEAGUE_CALENDAR() = default;

    void Generate(int start_year) override;
    void Clear() override;
    QVector<SCHEDULED_MATCH*> GetTour(int id) const override;
    QVector<SCHEDULED_MATCH*> GetTour(const QString& id) const override;
    QString GetTourName(int id) const override;
    void BindToursNames(QVector<QString> names = QVector<QString>{}) override;
    void PassAllGamesToEventSystem(EVENT_HANDLER* eventHandler) override;

    void BindToursNamesDefault();
private:
    QVector<QVector<SCHEDULED_MATCH*>> calendar;
    QVector<QString> toursNames;
};

#endif // LEAGUE_CALENDAR_H
