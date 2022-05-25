#ifndef CALENDAR_H
#define CALENDAR_H

#include "game/data/scheduled_match.h"

#include <QList>
#include <QPair>

class CALENDAR
{
public:
    CALENDAR(QList<TEAM*>& allTeams);
    CALENDAR(QList<TEAM*>& allTeams, QList<int>& startingStage);
    CALENDAR(QList<QPair<TEAM*, int>>& infoList);
    ~CALENDAR() = default;

    virtual void Generate(int start_year);
    virtual void Clear();
    virtual QList<SCHEDULED_MATCH*> GetTour(int id) const;
    virtual QList<SCHEDULED_MATCH*> GetTour(const QString& id) const;
    virtual QString GetTourName(int id) const;

    void ClearTeams();
    void SetTeams(QList<TEAM*>& teams, QList<int>&& startingStage = QList<int>{});
private:
    QList<TEAM*> allTeams;
    QList<int> teamStartingStage;
};

#endif // CALENDAR_H