#ifndef CALENDAR_H
#define CALENDAR_H

#include "game/data/scheduled_match.h"
#include "game/time/date.h"
#include "game/events/event_handler.h"
#include "game/events/event_match.h"

#include <QVector>
#include <QPair>

#include <random>
#include <algorithm>
#include <deque>
#include <numeric>

class CALENDAR
{
public:
    CALENDAR(QVector<TEAM*>& allTeams, COMPETITION* comp);
    CALENDAR(QVector<TEAM*>& allTeams, QVector<int>& startingStage, COMPETITION* comp);
    CALENDAR(QVector<QPair<TEAM*, int>>& infoList, COMPETITION* comp);
    ~CALENDAR() = default;

    virtual void Generate(int start_year) = 0;
    virtual void Clear() = 0;
    virtual QVector<SCHEDULED_MATCH*> GetTour(int id) const = 0;
    virtual QVector<SCHEDULED_MATCH*> GetTour(const QString& id) const = 0;
    virtual QString GetTourName(int id) const = 0;
    virtual void BindToursNames(QVector<QString> names = QVector<QString>{}) = 0;
    virtual void PassAllGamesToEventSystem(EVENT_HANDLER* eventHandler) = 0;

    void ClearTeams();
    void SetTeams(QVector<TEAM*>& teams, QVector<int>&& startingStage = QVector<int>{});
    int GetNextIdAndIncr();
protected:
    QVector<TEAM*> allTeams;
    QVector<int> teamStartingStage;
    COMPETITION* comp;
    int nextUniqueGameId = 0;
};

#endif // CALENDAR_H
