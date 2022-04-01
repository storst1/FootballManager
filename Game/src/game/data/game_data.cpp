#include "game_data.h"
#include "fifa.h"
#include "federation.h"
#include "league.h"
#include "team.h"
#include "player.h"
#include "player_position.h"

GAME_DATA::GAME_DATA(COUNTRY_MAP *countryMap) : countryMap(countryMap)
{
    InitPositions();
}

GAME_DATA::~GAME_DATA()
{
    delete fifa;
    qDeleteAll(federations);
    qDeleteAll(leagues);
    qDeleteAll(clubs);
    qDeleteAll(players);
}

QMap<int, FEDERATION *> GAME_DATA::getFederations() const
{
    return federations;
}

QMap<QString, LEAGUE *> GAME_DATA::getLeagues() const
{
    return leagues;
}

QMap<int, CLUB *> GAME_DATA::getClubs() const
{
    return clubs;
}

QMap<int, PLAYER *> GAME_DATA::getPlayers() const
{
    return players;
}

COUNTRY_MAP *GAME_DATA::getCountryMap() const
{
    return countryMap;
}

QMap<QPair<int, int>, PLAYER_POSITION *> GAME_DATA::getPositions() const
{
    return positions;
}

FEDERATION *GAME_DATA::implicitlyGetFederation(int id, QString& name)
{
    //Tries to find a pointer to federation with specified id, if such does not exist it creates a new federation
    if(federations.find(id) == federations.end()){
        FEDERATION* newFed = new FEDERATION(id, name, id, QList<LEAGUE*> {});
        federations.insert(id, newFed);
        return newFed;
    }
    return federations[id];
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

void GAME_DATA::addPos(PLAYER_POSITION *pos)
{
    positions.insert({pos->getFP(), pos->getSP()}, pos);
}

void GAME_DATA::InitPositions()
{
    //GK
    PLAYER_POSITION* gkPos = new PLAYER_POSITION(1, 0, "GK");
    addPos(gkPos);
    //Iterate through all the possible positions
    for(int i = 3; i < 15; ++i){
        PLAYER_POSITION* pos0 = new PLAYER_POSITION(i);
        addPos(pos0);
        pos0->setStrNameToAuto();
        for(int j = 3; j < 15; ++j){
            PLAYER_POSITION* pos = new PLAYER_POSITION(i, j);
            addPos(pos);
            pos0->setStrNameToAuto();
        }
    }
}
