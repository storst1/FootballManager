#include "game/data/team.h"
#include "game/data/coach.h"
#include "game/data/player.h"
#include "game/data/stadium.h"

TEAM::TEAM()
{

}

TEAM::TEAM(int id, QString name) : id(id), name(name)
{

}

TEAM::TEAM(int id, QString name, QList<PLAYER *> players, FEDERATION *fed)
    : id(id), name(name), players(players), fed(fed)
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

FEDERATION *TEAM::getFederation() const
{
    return fed;
}

int TEAM::getTV() const
{
    return 0;
}

int TEAM::getBudget() const
{
    return 0;
}

STADIUM *TEAM::getStadium() const
{
    return nullptr;
}

int TEAM::getPrestige() const
{
    return 0;
}

void TEAM::setPlayerList(QList<PLAYER *> playerList)
{
    players = playerList;
    SortPlayersListByPos();
}

void TEAM::SortPlayersListByPos()
{
    std::sort(players.begin(), players.end(), PLAYER::CompTwoPlayersByPos);
}

void TEAM::setFederation(FEDERATION *_fed)
{
    fed = _fed;
}

CLUB::CLUB(int id, QString name, int TV, int budget, QString stadName, int stadCap, int prestige) :
    TEAM(id, name), TV(TV), budget(budget), prestige(prestige)
{
    stadium = new STADIUM(stadName, stadCap);
}

int CLUB::getTV() const
{
    return TV;
}

int CLUB::getBudget() const
{
    return budget;
}

STADIUM *CLUB::getStadium() const
{
    return stadium;
}

int CLUB::getPrestige() const
{
    return prestige;
}

TEAM CLUB::getTeam(bool giveAccessToPlayersList)
{
    return TEAM(getId(), getName(), giveAccessToPlayersList ? getPlayers() : QList<PLAYER*>{}, getFederation());
}
