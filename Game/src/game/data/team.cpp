#include "team.h"
#include "coach.h"
#include "player.h"
#include "stadium.h"

TEAM::TEAM()
{

}

TEAM::TEAM(int id, QString name) : id(id), name(name)
{

}

TEAM::~TEAM()
{
    qDeleteAll(players);
    //delete coach;
}

int TEAM::getId() const
{
    return id;
}

QString TEAM::getName() const{
    return name;
}

QList<PLAYER*> TEAM::getPlayers(){
    return players;
}

void TEAM::setPlayerList(QList<PLAYER *> playerList)
{
    players = playerList;
}

CLUB::CLUB(int id, QString name, int TV, int budget, QString stadName, int stadCap, int prestige) :
    TEAM(id, name), TV(TV), budget(budget), prestige(prestige)
{
    stadium = new STADIUM(stadName, stadCap);
}
