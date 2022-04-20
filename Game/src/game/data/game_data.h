#ifndef GAME_DATA_H
#define GAME_DATA_H

#define MAX_AGE 100
#define MAX_TV 1000000000
#define MAX_SKILL 101

#include "game/data/data_defs.h"
#include "game/data/country_map.h"

#include <QMap>

class MainWindow;

class GAME_DATA
{
public:
    GAME_DATA(COUNTRY_MAP* countryMap);
    ~GAME_DATA();

    QMap<int, FEDERATION*> getFederations() const;
    QMap<QString, LEAGUE*> getLeagues() const;
    QList<LEAGUE*> getLeaguesList() const;
    QMap<int, CLUB*> getClubs() const;
    QMap<int, PLAYER*> getPlayers() const;
    QList<PLAYER*> getPlayersList() const;
    COUNTRY_MAP* getCountryMap() const;
    QMap<QPair<int, int>, PLAYER_POSITION*> getPositions() const;

    FEDERATION *implicitlyGetFederation(int id, QString &name);

    void addFederation(FEDERATION* fed);
    void addFederations(QList<FEDERATION*>& listFed);
    void addLeague(LEAGUE* league);
    void addLeagues(QList<LEAGUE*>& listLeague);
    void addClub(CLUB* club);
    void addClubs(QList<CLUB*>& listClubs);
    void addPlayer(PLAYER* player);
    void addPlayers(QList<PLAYER*>& listPlayers);
    void addPos(PLAYER_POSITION* pos);

    void InitPositions();

    QList<PLAYER*> getPlayersListConditional(int maxSize = -1,
                                             QList<FEDERATION*> nations = {},
                                             QList<FEDERATION*> secondNations = {},
                                             QString name = "",
                                             QString team = "",
                                             QList<LEAGUE*> leagues = {},
                                             int minAge = 0,
                                             int maxAge = MAX_AGE,
                                             QList<int> positions = {},
                                             QList<int> secondPositions = {},
                                             int minTV = 0,
                                             int maxTV = MAX_TV,
                                             int minSkill = 0,
                                             int maxSkill = MAX_SKILL
                                             ) const;
private:
    bool PlayerFirstNationConditionCheck(PLAYER* player, QList<FEDERATION*>& nations) const;
    bool PlayerSecondNationConditionCheck(PLAYER* player, QList<FEDERATION*>& nations) const;
    bool PlayerNameConditionCheck(PLAYER* player, QString& name) const;
    bool PlayerTeamConditionCheck(PLAYER* player, QString& team) const;
    bool PlayerLeagueConditionCheck(PLAYER* player, QList<LEAGUE*> leagues) const;
    bool PlayerAgeConditionCheck(PLAYER* player, int minAge, int maxAge) const;
    bool PlayerFirstPosConditionCheck(PLAYER* player, QList<int>& posList) const;
    bool PlayerSecondPosConditionCheck(PLAYER* player, QList<int>& posList) const;
    bool PlayerTVConditionCheck(PLAYER* player, int minTV, int maxTV) const;
    bool PlayerSkillConditionCheck(PLAYER* player, int minSkill, int maxSkill) const;
private:
    FIFA* fifa;
    QMap<int, FEDERATION*> federations;
    QMap<QString, LEAGUE*> leagues;
    QMap<int, CLUB*> clubs;
    QMap<int, PLAYER*> players;
    COUNTRY_MAP* countryMap;
    QMap<QPair<int, int>, PLAYER_POSITION*> positions;
};

#endif // GAME_DATA_H
