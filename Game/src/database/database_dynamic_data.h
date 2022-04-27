#ifndef DATABASE_DYNAMIC_DATA_H
#define DATABASE_DYNAMIC_DATA_H

#include "database.h"
#include "database_real_data.h"
#include "game/data/country_map.h"
#include "game/data/data_defs.h"
#include "game/data/game_data.h"

#include <QMap>

class MainWindow;

class DATABASE_DYNAMIC_DATA : public DATABASE
{
public:
    DATABASE_DYNAMIC_DATA(const QString& dbPath, const QString& connectionName);
    ~DATABASE_DYNAMIC_DATA() = default;

    void CopyDataFromRealDb(const QString &realDbPath, COUNTRY_MAP *countryMap) const;
    void CopyFederationsTable(QSqlQuery& query, COUNTRY_MAP* countryMap) const;
    void CopyLeaguesTable(QSqlQuery &query) const;
    void CopyClubsTable(QSqlQuery &query) const;
    void CopyPlayersTable(QSqlQuery &query) const;

    void FillGameData(GAME_DATA* gameData) const;
    void FillFederationsGameData(GAME_DATA* gameData) const;

    QList<LEAGUE*> InitLeagueList(QList<QString> &leagueIdsList, FEDERATION *curFed, GAME_DATA *gameData) const;
    QList<CLUB*> InitClubsByLeague(LEAGUE* league, GAME_DATA *gameData) const;
    QList<PLAYER*> InitPlayersByClub(CLUB *curClub, GAME_DATA *gameData) const;
};

#endif // DATABASE_DYNAMIC_DATA_H
