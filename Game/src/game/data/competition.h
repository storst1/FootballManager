#ifndef COMPETITION_H
#define COMPETITION_H

#include "game/data/data_defs.h"

class COMPETITION
{
public:
    COMPETITION();

    QString getId() const;
    QString getName() const;
    QVector<TEAM*> getTeams() const;
    int getTier() const;
    FEDERATION* getFederation() const;
    CALENDAR* getCalendar();

    void setId(QString& _id);
    void setTeamList(QVector<TEAM*> clubList);
    void setFederation(FEDERATION* _fed);
    void setName(QString& _name);

    virtual void setupCalendar() = 0;
    virtual void generateCalendar(int year) = 0;
protected:
    QString id;
    QString name;
    int tier;
    FEDERATION* fed;

    CALENDAR* calendar = nullptr;

    QVector<TEAM*> clubs;
};

#endif // COMPETITION_H
