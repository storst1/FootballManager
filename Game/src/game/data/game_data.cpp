#include "game_data.h"
#include "fifa.h"
#include "federation.h"
#include "league.h"
#include "team.h"
#include "player.h"

GAME_DATA::GAME_DATA()
{

}

GAME_DATA::~GAME_DATA()
{
    delete fifa;
    qDeleteAll(federations);
    qDeleteAll(leagues);
    qDeleteAll(clubs);
    qDeleteAll(players);
}

QMap<int, FEDERATION *> GAME_DATA::getFederations()
{
    return federations;
}

QMap<QString, LEAGUE *> GAME_DATA::getLeagues()
{
    return leagues;
}

QMap<int, CLUB *> GAME_DATA::getClubs()
{
    return clubs;
}

QMap<int, PLAYER *> GAME_DATA::getPlayers()
{
    return players;
}

void GAME_DATA::addFederation(FEDERATION *fed)
{
    federations[fed->getId()] = fed;
}

void GAME_DATA::addFederations(QList<FEDERATION *> &listFed)
{
    for(const auto f : listFed){
        addFederation(f);
    }
}

void GAME_DATA::addLeague(LEAGUE *league)
{
    leagues[league->getId()] = league;
}

void GAME_DATA::addLeagues(QList<LEAGUE *> &listLeague)
{
    for(const auto l : listLeague){
        addLeague(l);
    }
}

void GAME_DATA::addClub(CLUB *club)
{
    clubs[club->getId()] = club;
}

void GAME_DATA::addClubs(QList<CLUB *> &listClubs)
{
    for(const auto c : listClubs){
        addClub(c);
    }
}

void GAME_DATA::addPlayer(PLAYER *player)
{
    players[player->getId()] = player;
}

void GAME_DATA::addPlayers(QList<PLAYER *> &listPlayers)
{
    for(const auto p : listPlayers){
        addPlayer(p);
    }
}
