#include "database_dynamic_data.h"
#include "game/data/game_data.h"
#include "game/data/player.h"
#include "game/data/federation.h"
#include "game/data/team.h"
#include "game/data/league.h"

DATABASE_DYNAMIC_DATA::DATABASE_DYNAMIC_DATA(const QString &dbPath, const QString &connectionName)
    : DATABASE(dbPath, connectionName)
{
}

void DATABASE_DYNAMIC_DATA::CopyDataFromRealDb(const QString& realDbPath, COUNTRY_MAP* countryMap)
{
    QSqlQuery query(*db);
    query.exec("ATTACH DATABASE '" + realDbPath + "' AS real;");
    DATABASE::PrintSqlExecInfoIfErr(query);
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
        DATABASE::PrintSqlExecInfoIfErr(query);
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
    query.exec("INSERT INTO clubs"
               " (id, name, leagueId, stadiumName, stadiumCapacity, playersTV, transferBudget, prestige) "
               "SELECT "
               " id, name, league, stadiumName, stadiumCapacity, playersTV, budget, prestige "
               " FROM real.clubs");
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
    DATABASE::PrintSqlExecInfoIfErr(query);
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
        FEDERATION* curFed = new FEDERATION(fedId, name, countryId);
        gameData->addFederation(curFed);
        QList<LEAGUE*> leaguesList = InitLeagueList(leagueIdsList, gameData);
        curFed->setLeagues(leaguesList);
    }
}

QList<LEAGUE *> DATABASE_DYNAMIC_DATA::InitLeagueList(const QList<QString> &leagueIdsList, GAME_DATA *gameData)
{
    QList<LEAGUE*> leagueList;
    QSqlQuery query(*db);
    for(int i = 0; i < leagueIdsList.size(); ++i){
        LEAGUE* curLeague = new LEAGUE();
        query.exec("SELECT name FROM leagues WHERE id = " + leagueIdsList[i] + ";");
        DATABASE::PrintSqlExecInfoIfErr(query);
        QString curName = query.value(0).toString();
        int curTier = i + 1;
        curLeague->setName(curName);
        curLeague->setTier(curTier);
        leagueList.push_back(curLeague);
    }
    for(const auto &l : leagueList){
        l->setClubList(InitClubsByLeague(l->getId(), gameData));
    }
    return leagueList;
}

QList<CLUB *> DATABASE_DYNAMIC_DATA::InitClubsByLeague(const QString &leagueId, GAME_DATA *gameData)
{
    QSqlQuery query(*db);
    QList<CLUB*> clubList;
    query.exec("SELECT "
               "id, name, stadiumName, stadiumCapacity, playersTV, transferBudget, prestige "
               "FROM clubs "
               "WHERE leagueId = '" + leagueId + "';");
    DATABASE::PrintSqlExecInfoIfErr(query);
    while(query.next()){
        int curId = query.value(0).toInt();
        QString curName = query.value(1).toString();
        QString curSN = query.value(2).toString();
        int curSC = query.value(3).toInt();
        int curTV = query.value(4).toInt();
        int curTB = query.value(5).toInt();
        int curPrestige = query.value(6).toInt();
        CLUB* curClub = new CLUB(curId, curName, curTV, curTB, curSN, curSC, curPrestige);
        curClub->setPlayerList(InitPlayersByClub(curClub, gameData));
        clubList.push_back(curClub);
    }
    return clubList;
}

QList<PLAYER *> DATABASE_DYNAMIC_DATA::InitPlayersByClub(CLUB* curClub, GAME_DATA *gameData)
{
    QMap<QPair<int, int>, PLAYER_POSITION*> positionsMap = gameData->getPositions();
    const int clubId = curClub->getId();
    QSqlQuery query(*db);
    QList<PLAYER*> playersList;
    query.exec("SELECT id, name, TV, age, FN, SN, FP, SP, skill, height FROM players "
               "WHERE club = '" + QString::number(clubId) + "';");
    DATABASE::PrintSqlExecInfoIfErr(query);
    while(query.exec()){
        int curId = query.value(0).toInt();
        QString curName = query.value(1).toString();
        int curTV = query.value(2).toInt();
        int curAge = query.value(3).toInt();
        int curFNid = query.value(4).toInt();
        int curSNid = query.value(5).toInt();
        int curFPid = query.value(6).toInt();
        int curSPid = query.value(7).toInt();
        float curSkill = query.value(8).toFloat();
        QString curH = query.value(9).toString();
        QString FFstr = gameData->getCountryMap()->getById(curFNid);
        FEDERATION* FF = gameData->implicitlyGetFederation(curFNid, FFstr);
        QString SFstr;
        FEDERATION* SF = nullptr;
        if(curSNid != 0){
            SFstr = gameData->getCountryMap()->getById(curSNid);
            SF = gameData->implicitlyGetFederation(curSNid, SFstr);
        }

        PLAYER* curPlayer = new PLAYER(curId, curName, curTV, curAge, curSkill, FF, SF, positionsMap[{curFPid, curSPid}], curH);
        curPlayer->setClub(curClub);
        playersList.push_back(curPlayer);
    }
    return playersList;
}
