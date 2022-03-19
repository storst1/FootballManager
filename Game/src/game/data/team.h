#ifndef TEAM_H
#define TEAM_H

#include "game/data/data_defs.h"

class COACH;
class PLAYER;
class STADIUM;

class TEAM
{
public:
    TEAM();
    ~TEAM();

protected:
    QString name;
    QList<PLAYER*> players;
    COACH* coach;
    STADIUM* stadium;
};


//CLASS NATIONAL TEAM
class NATIONAL_TEAM : public TEAM
{
public:
    NATIONAL_TEAM();
    ~NATIONAL_TEAM() = default;
};


//CLASS CLUB
class CLUB : public TEAM
{
public:
    CLUB();
    ~CLUB() = default;

private:
    int TV;
    int budget;

};

#endif // TEAM_H
