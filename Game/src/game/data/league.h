#ifndef LEAGUE_H
#define LEAGUE_H

#include "game/data/data_defs.h"

class LEAGUE
{
public:
    LEAGUE();
    ~LEAGUE();

    QString getId() const;
    QString getName() const;
    QList<CLUB*> getClubs() const;
    int getTier() const;
    FEDERATION* getFederation() const;

    void setName(QString& _name);
    void setTier(int t);
    void setId(QString& _id);
    void setClubList(QList<CLUB*> clubList);
    void setFederation(FEDERATION* _fed);
private:
    QString id;
    QString name;
    int tier;
    FEDERATION* fed;

    QList<CLUB*> clubs;

    CUP* leagueCup = nullptr; //may be nullptr

    //stats fields
    TABLE* table;
};

#endif // LEAGUE_H
