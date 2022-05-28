#ifndef CALENDAR_H
#define CALENDAR_H

#include "game/data/scheduled_match.h"

#include <QVector>
#include <QPair>

class CALENDAR
{
public:
    CALENDAR(QVector<TEAM*>& allTeams);
    CALENDAR(QVector<TEAM*>& allTeams, QVector<int>& startingStage);
    CALENDAR(QVector<QPair<TEAM*, int>>& infoList);
    ~CALENDAR() = default;

    virtual void Generate(int start_year) = 0;
    virtual void Clear() = 0;
    virtual QVector<SCHEDULED_MATCH*> GetTour(int id) const = 0;
    virtual QVector<SCHEDULED_MATCH*> GetTour(const QString& id) const = 0;
    virtual QString GetTourName(int id) const = 0;

    void ClearTeams();
    void SetTeams(QVector<TEAM*>& teams, QVector<int>&& startingStage = QVector<int>{});
protected:
    QVector<TEAM*> allTeams;
    QVector<int> teamStartingStage;
};

#endif // CALENDAR_H
