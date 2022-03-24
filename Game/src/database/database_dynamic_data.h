#ifndef DATABASE_DYNAMIC_DATA_H
#define DATABASE_DYNAMIC_DATA_H

#include "database.h"
#include "database_real_data.h"
#include "game/data/country_map.h"

class DATABASE_DYNAMIC_DATA : public DATABASE
{
public:
    DATABASE_DYNAMIC_DATA(const QString& dbPath, const QString& connectionName);
    ~DATABASE_DYNAMIC_DATA() = default;

    //void LoadAllDataFromAPILists();
    void CopyDataFromRealDb(const QString &realDbPath, COUNTRY_MAP *countryMap);
    void CopyFederationsTable(QSqlQuery& query, COUNTRY_MAP* countryMap);
    void CopyLeaguesTable(QSqlQuery &query);
    void CopyClubsTable(QSqlQuery &query);
    void CopyPlayersTable(QSqlQuery &query);
};

#endif // DATABASE_DYNAMIC_DATA_H
