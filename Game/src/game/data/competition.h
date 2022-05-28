#ifndef COMPETITION_H
#define COMPETITION_H

#include "game/data/data_defs.h"

class COMPETITION
{
public:
    COMPETITION();

    QString getId() const;
    QString getName() const;
    QVector<CLUB*> getClubs() const;
    int getTier() const;
    FEDERATION* getFederation() const;

    void setId(QString& _id);
    void setClubList(QVector<CLUB*> clubList);
    void setFederation(FEDERATION* _fed);
    void setName(QString& _name);
private:
    QString id;
    QString name;
    int tier;
    FEDERATION* fed;

    QVector<CLUB*> clubs;
};

#endif // COMPETITION_H
