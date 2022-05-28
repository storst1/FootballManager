#ifndef CUP_CALENDAR_H
#define CUP_CALENDAR_H

#include "game/data/calendar.h"

class CUP_CALENDAR : public CALENDAR
{
public:
    CUP_CALENDAR(QVector<TEAM*>& allTeams, COMPETITION* comp);
    CUP_CALENDAR(QVector<TEAM*>& allTeams, QVector<int>& startingStage, COMPETITION* comp);
    CUP_CALENDAR(QVector<QPair<TEAM*, int>>& infoList, COMPETITION* comp);
    ~CUP_CALENDAR() = default;

    void Generate(int start_year) override;
    void Clear() override;
    QVector<SCHEDULED_MATCH*> GetTour(int id) const override;
    QVector<SCHEDULED_MATCH*> GetTour(const QString& id) const override;
    QString GetTourName(int id) const override;
    void BindToursNames(QVector<QString> names = QVector<QString>{}) override;
private:
    QVector<QVector<SCHEDULED_MATCH*>> calendar;
    QVector<QString> toursNames;
};

#endif // CUP_CALENDAR_H
