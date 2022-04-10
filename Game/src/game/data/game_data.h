#ifndef GAME_DATA_H
#define GAME_DATA_H

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
