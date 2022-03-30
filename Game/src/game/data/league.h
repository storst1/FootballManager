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

    void setName(QString& _name);
    void setTier(int t);
    void setClubList(QList<CLUB*> clubList);
private:
    QString id;
    QString name;
    int tier;

    QList<CLUB*> clubs;

    CUP* leagueCup = nullptr; //may be nullptr

    //stats fields
    TABLE* table;
};

#endif // LEAGUE_H
