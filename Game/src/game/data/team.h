#ifndef TEAM_H
#define TEAM_H

#include "game/data/data_defs.h"

class TEAM
{
public:
    TEAM();
    ~TEAM();

    int getId();
    QString getName();
    QList<PLAYER*> getPlayers();
protected:
    int id;
    QString name;
    QList<PLAYER*> players;
    //COACH* coach;
};


//CLASS NATIONAL TEAM
class NATIONAL_TEAM : public TEAM
{
public:
    NATIONAL_TEAM() = default;
    ~NATIONAL_TEAM() = default;
private:
    QList<STADIUM*> stadiumList;
};


//CLASS CLUB
class CLUB : public TEAM
{
public:
    CLUB() = default;
    ~CLUB() = default;

private:
    int TV;
    int budget;
    STADIUM* stadium;
};

#endif // TEAM_H
