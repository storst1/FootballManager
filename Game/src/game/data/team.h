#ifndef TEAM_H
#define TEAM_H

#include "game/data/data_defs.h"

class TEAM
{
public:
    TEAM();
    TEAM(int id, QString name);
    TEAM(int id, QString name, QList<PLAYER*> players, FEDERATION* fed);
    ~TEAM();

    int getId() const;
    QString getName() const;
    QList<PLAYER*> getPlayers();
    FEDERATION* getFederation() const;

    void setPlayerList(QList<PLAYER*> playerList);
    void SortPlayersListByPos();
    void setFederation(FEDERATION* _fed);
protected:
    int id;
    QString name;
    QList<PLAYER*> players;
    FEDERATION* fed;
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

    int getTV() const;
    int getBudget() const;
    STADIUM *getStadium() const;
    int getPrestige() const;

    TEAM getTeam(bool giveAccessToPlayersList = false);

private:
    int TV;
    int budget;
    STADIUM* stadium;
    int prestige;
};

#endif // TEAM_H
