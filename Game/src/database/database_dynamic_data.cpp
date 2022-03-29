#include "database_dynamic_data.h"
#include "game/data/game_data.h"
#include "game/data/player.h"
#include "game/data/federation.h"
#include "game/data/team.h"

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
    FillFederationsGameData(gameData);
}

void DATABASE_DYNAMIC_DATA::FillFederationsGameData(GAME_DATA *gameData)
{
    QSqlQuery query(*db);
    query.exec("SELECT * from federations");
    while(query.next()){
        int fedId = query.value(0).toInt();
        QString name = query.value(1).toString();
        int countryId = query.value(2).toInt();
        QList<QString> leagueIdsList;
        for(int i = 3; i <= 5; ++i){
            QString curLeague = query.value(i).toString();
            if(curLeague != ""){
                leagueIdsList.push_back(curLeague);
            }
        }
        QList<LEAGUE*> leaguesList = InitLeagueList(leagueIdsList);
        gameData->addFederation(new FEDERATION(fedId, name, countryId, leaguesList));
    }
}

QList<LEAGUE *> DATABASE_DYNAMIC_DATA::InitLeagueList(QList<QString> &leagueIdsList)
{
    QSqlQuery query(*db);
    for(int i = 0; i < leagueIdsList.size(); ++i){
        CLUB* c = new CLUB();
        PLAYER* p = new PLAYER();
        NATIONAL_TEAM* nt = new NATIONAL_TEAM();

    }
}

/*
void DATABASE_DYNAMIC_DATA::LoadAllDataFromAPILists()
{

}
*/
