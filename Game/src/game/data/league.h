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
private:
    QString id;
    QString name;
    int tier;

    QList<CLUB*> clubs;

    CUP* leagueCup; //may be nullptr

    //stats fields
    TABLE* table;
};

#endif // LEAGUE_H
