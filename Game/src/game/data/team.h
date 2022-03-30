#ifndef TEAM_H
#define TEAM_H

#include "game/data/data_defs.h"

class TEAM
{
public:
    TEAM();
    TEAM(int id, QString name);
    ~TEAM();

    int getId();
    QString getName();
    QList<PLAYER*> getPlayers();

    void setPlayerList(QList<PLAYER*> playerList);
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
    CLUB(int id, QString name, int TV, int budget, QString stadName, int stadCap, int prestige);
    ~CLUB() = default;

private:
    int TV;
    int budget;
    STADIUM* stadium;
    int prestige;
};

#endif // TEAM_H
