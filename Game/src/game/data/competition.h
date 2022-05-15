#ifndef COMPETITION_H
#define COMPETITION_H

#include "game/data/data_defs.h"

class COMPETITION
{
public:
    COMPETITION();

    QString getId() const;
    QString getName() const;
    QList<CLUB*> getClubs() const;
    int getTier() const;
    FEDERATION* getFederation() const;

    void setId(QString& _id);
    void setClubList(QList<CLUB*> clubList);
    void setFederation(FEDERATION* _fed);
    void setName(QString& _name);
private:
    QString id;
    QString name;
    int tier;
    FEDERATION* fed;

    QList<CLUB*> clubs;
};

#endif // COMPETITION_H
