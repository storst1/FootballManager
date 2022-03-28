#include "team.h"
#include "coach.h"
#include "player.h"
#include "stadium.h"

TEAM::TEAM()
{

}

TEAM::~TEAM()
{
    qDeleteAll(players);
    //delete coach;
}

int TEAM::getId()
{
    return id;
}

QString TEAM::getName(){
    return name;
}

QList<PLAYER*> TEAM::getPlayers(){
    return players;
}
