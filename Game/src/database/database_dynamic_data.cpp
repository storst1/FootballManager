#include "database_dynamic_data.h"

DATABASE_DYNAMIC_DATA::DATABASE_DYNAMIC_DATA(const QString &dbPath, const QString &connectionName)
    : DATABASE(dbPath, connectionName)
{
}

void DATABASE_DYNAMIC_DATA::CopyDataFromRealDb(const QString& realDbPath, COUNTRY_MAP* countryMap)
{
    QSqlQuery query(*db);
    query.exec("ATTACH DATABASE '" + realDbPath + "' AS real;");
    CopyFederationsTable(query, countryMap);
    CopyLeaguesTable(query);
    CopyClubsTable(query);
    CopyPlayersTable(query);
}

void DATABASE_DYNAMIC_DATA::CopyFederationsTable(QSqlQuery& query, COUNTRY_MAP* countryMap)
{
    DeleteTableInfo("federations");
    query.exec("INSERT INTO federations"
               "(id, name, firstLeague, secondLeague, thirdLeague)"
               " SELECT "
               "id, country, league_first, league_second, league_third "
               " FROM real.federations");

    qDebug() << "Copying federations data into dynamic database finished. Last error: " + query.lastError().text();

    query.exec("SELECT id, country FROM real.federations");
    QMap<int, int> countryIdByFedId;
    while(query.next()){
        int curFedId = query.value(0).toInt();
        QString curCountryName = query.value(1).toString();
        int curCountryId = countryMap->getByName(curCountryName);
        countryIdByFedId.insert(curFedId, curCountryId);
        query.exec("UPDATE federations SET countryId = " +
                   QString::number(curCountryId) +
                   " WHERE name = '" + curCountryName + "';");
    }

    qDebug() << "Updating federations data into dynamic database finished. Last error: " + query.lastError().text();
}

void DATABASE_DYNAMIC_DATA::CopyLeaguesTable(QSqlQuery& query)
{
    DeleteTableInfo("leagues");
    query.exec("INSERT INTO leagues (id, name, fed_id) SELECT id, name, federation FROM real.leagues");
    qDebug() << "Copying league data into dynamic database finished. Last error: " + query.lastError().text();
}

void DATABASE_DYNAMIC_DATA::CopyClubsTable(QSqlQuery& query)
{
    DeleteTableInfo("clubs");
    query.exec("INSERT INTO clubs SELECT * FROM real.clubs");
    qDebug() << "Copying clubs data into dynamic database finished. Last error: " + query.lastError().text();
}

void DATABASE_DYNAMIC_DATA::CopyPlayersTable(QSqlQuery& query)
{
    DeleteTableInfo("players");
    query.exec("INSERT INTO players"
               "(id, name, club, TV, age, FN, SN, FP, SP, skill, height)"
               " SELECT "
               "id, name, club, TW, age, FN, SN, FP, SP, skill, height"
               " FROM real.players");

    qDebug() << "Copying players data into dynamic database finished. Last error: " + query.lastError().text();
}

void DATABASE_DYNAMIC_DATA::FillGameData(GAME_DATA *gameData)
{

}

/*
void DATABASE_DYNAMIC_DATA::LoadAllDataFromAPILists()
{

}
*/
