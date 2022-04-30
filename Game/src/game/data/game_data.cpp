#include "game/data/game_data.h"
#include "game/data/fifa.h"
#include "game/data/federation.h"
#include "game/data/league.h"
#include "game/data/team.h"
#include "game/data/player.h"
#include "game/data/player_position.h"
#include "main/mainwindow.h"

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

QList<FEDERATION *> GAME_DATA::getFederationsList() const
{
    //Iterates through the map and returns all the existing pointers to FEDERATION
    QList<FEDERATION*> list;
    for(const auto& f : federations){
        list.push_back(f);
    }
    return list;
}

QMap<QString, LEAGUE *> GAME_DATA::getLeagues() const
{
    return leagues;
}

QList<LEAGUE *> GAME_DATA::getLeaguesList() const
{
    //Iterates through the map and returns all the existing pointers to LEAGUE
    QList<LEAGUE*> list;
    for(const auto& l : leagues){
        list.push_back(l);
    }
    return list;
}

QMap<int, CLUB *> GAME_DATA::getClubs() const
{
    return clubs;
}

QMap<int, PLAYER *> GAME_DATA::getPlayers() const
{
    return players;
}

QList<PLAYER *> GAME_DATA::getPlayersList() const
{
    //Iterates through the map and returns all the existing pointers to PLAYER
    QList<PLAYER*> list;
    for(const auto& p : players){
        list.push_back(p);
    }
    return list;
}

COUNTRY_MAP *GAME_DATA::getCountryMap() const
{
    return countryMap;
}

QMap<QPair<int, int>, PLAYER_POSITION *> GAME_DATA::getPositions() const
{
    return positions;
}

FEDERATION *GAME_DATA::getFederationById(int id) const
{
    return federations[id];
}

FEDERATION *GAME_DATA::implicitlyGetFederation(int id, QString& name)
{
    //Tries to find a pointer to federation with specified id, if such does not exist it creates a new federation
    if(federations.find(id) == federations.end()){
        FEDERATION* newFed = new FEDERATION(id, name, id, QList<LEAGUE*> {});
        newFed->setFlag(new QPixmap(MainWindow::GetFlagPath(newFed, "48x30")));
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
            if(j == i){
                continue;
            }
            PLAYER_POSITION* pos = new PLAYER_POSITION(i, j);
            addPos(pos);
            pos->setStrNameToAuto();
        }
    }
}

QList<PLAYER *> GAME_DATA::getPlayersListConditional(int maxSize,
                                                     QList<FEDERATION *> nations,
                                                     QList<FEDERATION *> secondNations,
                                                     QString name,
                                                     QString team,
                                                     QList<LEAGUE *> leagues,
                                                     int minAge,
                                                     int maxAge,
                                                     QList<int> positions,
                                                     QList<int> secondPositions,
                                                     int minTV,
                                                     int maxTV,
                                                     int minSkill,
                                                     int maxSkill
                                                     ) const
{
    QList<PLAYER*> list = getPlayersList();
    std::sort(list.begin(), list.end(), PLAYER::CompTwoPlayersBySkillReversed);
    QList<PLAYER*> listToReturn;
    for(int i = 0; i < list.size(); ++i){
        if(!PlayerFirstNationConditionCheck(list[i], nations)){
            continue;
        }
        if(!PlayerSecondNationConditionCheck(list[i], secondNations)){
            continue;
        }
        if(!PlayerNameConditionCheck(list[i], name)){
            continue;
        }
        if(!PlayerTeamConditionCheck(list[i], team)){
            continue;
        }
        if(!PlayerLeagueConditionCheck(list[i], leagues)){
            continue;
        }
        if(!PlayerAgeConditionCheck(list[i], minAge, maxAge)){
            continue;
        }
        if(!PlayerFirstPosConditionCheck(list[i], positions)){
            continue;
        }
        if(!PlayerSecondPosConditionCheck(list[i], secondPositions)){
            continue;
        }
        if(!PlayerTVConditionCheck(list[i], minTV, maxTV)){
            continue;
        }
        if(!PlayerSkillConditionCheck(list[i], minSkill, maxSkill)){
            continue;
        }
        //If player hasn't been skipped up to this point, that means he's meeting all the required conditions
        listToReturn.push_back(list[i]);
        if(maxSize > 0 && listToReturn.size() == maxSize){
            return listToReturn;
        }
    }
    return listToReturn;
}

QList<PLAYER *> GAME_DATA::getPlayersListConditionalByFilter(int maxSize, PLAYER_SEARCH_FILTER filter) const
{
    return getPlayersListConditional(maxSize,
                                     filter.getNations(),
                                     filter.getSecondNations(),
                                     filter.getName(),
                                     filter.getTeam(),
                                     filter.getLeagues(),
                                     filter.getMinAge(),
                                     filter.getMaxAge(),
                                     filter.getPositions(),
                                     filter.getSecondPositions(),
                                     filter.getMinTV(),
                                     filter.getMaxTV(),
                                     filter.getMinSkill(),
                                     filter.getMaxSkill()
                                     );
}

QList<QPair<QString, int> > GAME_DATA::getPositionsSimplifiedList()
{
    QList<QPair<QString, int>> list;
    list.push_back({"GK", 1});
    list.push_back({"CB", 3});
    list.push_back({"LB", 4});
    list.push_back({"RB", 5});
    list.push_back({"DM", 6});
    list.push_back({"CM", 7});
    list.push_back({"RM", 8});
    list.push_back({"LM", 9});
    list.push_back({"CAM", 10});
    list.push_back({"LW", 11});
    list.push_back({"RW", 12});
    list.push_back({"CF", 13});
    list.push_back({"ST", 14});
    return list;
}

bool GAME_DATA::PlayerFirstNationConditionCheck(PLAYER *player, QList<FEDERATION *> &nations) const
{
    if(nations.empty()){
        return true;
    }
    for(const auto &n : nations){
        if(player->getFF() == n){
            return true;
        }
    }
    return false;
}

bool GAME_DATA::PlayerSecondNationConditionCheck(PLAYER *player, QList<FEDERATION *> &nations) const
{
    if(nations.empty()){
        return true;
    }
    for(const auto &n : nations){
        if(player->getSF() == n){
            return true;
        }
    }
    return false;
}

bool GAME_DATA::PlayerNameConditionCheck(PLAYER *player, QString &name) const
{
    if(name == ""){
        return true;
    }
    return player->getName().contains(name, Qt::CaseInsensitive);
}

bool GAME_DATA::PlayerTeamConditionCheck(PLAYER *player, QString &team) const
{
    if(team == ""){
        return true;
    }
    return player->getClub()->getName().contains(team, Qt::CaseInsensitive);
}

bool GAME_DATA::PlayerLeagueConditionCheck(PLAYER *player, QList<LEAGUE *> leagues) const
{
    //TO DO: Implement this method

    /*
    if(leagues.empty()){
        return true;
    }
    for(const auto& l : leagues){
        if(player->getClub()->)
    }
    */
    return true;
}

bool GAME_DATA::PlayerAgeConditionCheck(PLAYER *player, int minAge, int maxAge) const
{
    return (player->getAge() >= minAge && player->getAge() <= maxAge);
}

bool GAME_DATA::PlayerFirstPosConditionCheck(PLAYER *player, QList<int> &posList) const
{
    if(posList.empty()){
        return true;
    }
    for(const auto &p : posList){
        if(player->getPos()->getFP() == p){
            return true;
        }
    }
    return false;
}

bool GAME_DATA::PlayerSecondPosConditionCheck(PLAYER *player, QList<int> &posList) const
{
    if(posList.empty()){
        return true;
    }
    for(const auto &p : posList){
        if(player->getPos()->getSP() == p){
            return true;
        }
    }
    return false;
}

bool GAME_DATA::PlayerTVConditionCheck(PLAYER *player, int minTV, int maxTV) const
{
    return (player->getTV() >= minTV && player->getTV() <= maxTV);
}

bool GAME_DATA::PlayerSkillConditionCheck(PLAYER *player, int minSkill, int maxSkill) const
{
    return (player->getSkill() >= minSkill && player->getSkill() <= maxSkill);
}
