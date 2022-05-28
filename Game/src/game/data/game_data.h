#ifndef GAME_DATA_H
#define GAME_DATA_H

#define MAX_PLAYER_AGE 100
#define MAX_PLAYER_TV 1000000000
#define MAX_PLAYER_SKILL 101

#include "game/data/data_defs.h"
#include "game/data/country_map.h"
#include "game/data/player_search_filter.h"

#include <QMap>

class MainWindow;

class GAME_DATA
{
public:
    GAME_DATA(COUNTRY_MAP* countryMap);
    ~GAME_DATA();

    QMap<int, FEDERATION*> getFederations() const;
    QVector<FEDERATION*> getFederationsList() const;
    QMap<QString, LEAGUE*> getLeagues() const;
    QVector<LEAGUE*> getLeaguesList() const;
    QMap<int, CLUB*> getClubs() const;
    QMap<int, PLAYER*> getPlayers() const;
    QVector<PLAYER*> getPlayersList() const;
    COUNTRY_MAP* getCountryMap() const;
    QMap<QPair<int, int>, PLAYER_POSITION*> getPositions() const;

    FEDERATION *getFederationById(int id) const;

    FEDERATION *implicitlyGetFederation(int id, QString &name);

    void addFederation(FEDERATION* fed);
    void addFederations(QVector<FEDERATION*>& listFed);
    void addLeague(LEAGUE* league);
    void addLeagues(QVector<LEAGUE*>& listLeague);
    void addClub(CLUB* club);
    void addClubs(QVector<CLUB*>& listClubs);
    void addPlayer(PLAYER* player);
    void addPlayers(QVector<PLAYER*>& listPlayers);
    void addPos(PLAYER_POSITION* pos);

    void InitPositions();

    QVector<PLAYER*> getPlayersListConditional(int maxSize = -1,
                                             QVector<FEDERATION*> nations = {},
                                             QVector<FEDERATION*> secondNations = {},
                                             QString name = "",
                                             QString team = "",
                                             QVector<LEAGUE*> leagues = {},
                                             int minAge = 0,
                                             int maxAge = MAX_PLAYER_AGE,
                                             QVector<int> positions = {},
                                             QVector<int> secondPositions = {},
                                             int minTV = 0,
                                             int maxTV = MAX_PLAYER_TV,
                                             int minSkill = 0,
                                             int maxSkill = MAX_PLAYER_SKILL
                                             ) const;
    QVector<PLAYER*> getPlayersListConditionalByFilter(int maxSize = -1, PLAYER_SEARCH_FILTER filter = PLAYER_SEARCH_FILTER()) const;

    static QVector<QPair<QString, int>> getPositionsSimplifiedList();
private:
    bool PlayerFirstNationConditionCheck(PLAYER* player, QVector<FEDERATION*>& nations) const;
    bool PlayerSecondNationConditionCheck(PLAYER* player, QVector<FEDERATION*>& nations) const;
    bool PlayerNameConditionCheck(PLAYER* player, QString& name) const;
    bool PlayerTeamConditionCheck(PLAYER* player, QString& team) const;
    bool PlayerLeagueConditionCheck(PLAYER* player, QVector<LEAGUE*> leagues) const;
    bool PlayerAgeConditionCheck(PLAYER* player, int minAge, int maxAge) const;
    bool PlayerFirstPosConditionCheck(PLAYER* player, QVector<int>& posList) const;
    bool PlayerSecondPosConditionCheck(PLAYER* player, QVector<int>& posList) const;
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
