#ifndef DATABASE_DYNAMIC_DATA_H
#define DATABASE_DYNAMIC_DATA_H

#include "database.h"
#include "database_real_data.h"
#include "game/data/country_map.h"
#include "game/data/data_defs.h"
#include "game/data/game_data.h"

#include <QMap>

class DATABASE_DYNAMIC_DATA : public DATABASE
{
public:
    DATABASE_DYNAMIC_DATA(const QString& dbPath, const QString& connectionName);
    ~DATABASE_DYNAMIC_DATA() = default;

    void CopyDataFromRealDb(const QString &realDbPath, COUNTRY_MAP *countryMap);
    void CopyFederationsTable(QSqlQuery& query, COUNTRY_MAP* countryMap);
    void CopyLeaguesTable(QSqlQuery &query);
    void CopyClubsTable(QSqlQuery &query);
    void CopyPlayersTable(QSqlQuery &query);

    void FillGameData(GAME_DATA* gameData);
    void FillFederationsGameData(GAME_DATA* gameData);

    QList<LEAGUE*> InitLeagueList(const QList<QString> &leagueIdsList);
    QList<CLUB*> InitClubsByLeague(const QString &leagueId);
    QList<PLAYER*> InitPlayersByClub(const int clubId);
};

#endif // DATABASE_DYNAMIC_DATA_H
