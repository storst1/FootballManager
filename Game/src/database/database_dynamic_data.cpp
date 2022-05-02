#define DEFAULT_CONTRACT_EXPIRING_DATE 20220629

#include "database/database_dynamic_data.h"
#include "main/mainwindow.h"
#include "game/data/player.h"
#include "game/data/federation.h"
#include "game/data/team.h"
#include "game/data/league.h"
#include "game/time/date.h"
#include "game/data/player_position.h"
#include "game/data/stadium.h"

DATABASE_DYNAMIC_DATA::DATABASE_DYNAMIC_DATA(const QString &dbPath,
                                             const QString &connectionName,
                                             DATABASE_SKILL_CONVERTER* skillConvDb)
    : DATABASE(dbPath, connectionName), skillConvDb(skillConvDb)
{
}

void DATABASE_DYNAMIC_DATA::CopyDataFromRealDb(const QString& realDbPath, COUNTRY_MAP* countryMap) const
{
    QSqlQuery query(*db);
    query.exec("ATTACH DATABASE '" + realDbPath + "' AS real;");
    DATABASE::PrintSqlExecInfoIfErr(query);
    CopyFederationsTable(query, countryMap);
    CopyLeaguesTable(query);
    CopyClubsTable(query);
    CopyPlayersTable(query);
}

void DATABASE_DYNAMIC_DATA::CopyFederationsTable(QSqlQuery& query, COUNTRY_MAP* countryMap) const
{
    DeleteTableInfo("federations");
    query.exec("INSERT INTO federations"
               "(id, name, firstLeague, secondLeague, thirdLeague)"
               " SELECT "
               "id, country, league_first, league_second, league_third "
               " FROM real.federations");

    qDebug() << "Copying federations data into dynamic database finished. Last error: " + query.lastError().text();

    query.exec("SELECT id, name FROM federations");
    DATABASE::PrintSqlExecInfoIfErr(query);
    QSqlQuery updQuery(*db);
    while(query.next()){
        int curFedId = query.value(0).toInt();
        QString curCountryName = query.value(1).toString();
        int curCountryId = countryMap->getByName(curCountryName);
        updQuery.exec("UPDATE federations SET countryId = " +
                   QString::number(curCountryId) +
                   " WHERE id = '" + QString::number(curFedId) + "';");
        DATABASE::PrintSqlExecInfoIfErr(updQuery);
    }

    qDebug() << "Copying federations data into dynamic database finished. Last error: " + query.lastError().text();
}

void DATABASE_DYNAMIC_DATA::CopyLeaguesTable(QSqlQuery& query) const
{
    DeleteTableInfo("leagues");
    query.exec("INSERT INTO leagues (id, name, fed_id) SELECT id, name, federation FROM real.leagues");
    qDebug() << "Copying league data into dynamic database finished. Last error: " + query.lastError().text();
}

void DATABASE_DYNAMIC_DATA::CopyClubsTable(QSqlQuery& query) const
{
    DeleteTableInfo("clubs");
    query.exec("INSERT INTO clubs"
               " (id, name, leagueId, stadiumName, stadiumCapacity, playersTV, transferBudget, prestige) "
               "SELECT "
               " id, name, league, stadiumName, stadiumCapacity, playersTV, budget, prestige "
               " FROM real.clubs");
    qDebug() << "Copying clubs data into dynamic database finished. Last error: " + query.lastError().text();
}

void DATABASE_DYNAMIC_DATA::CopyPlayersTable(QSqlQuery& query) const
{
    DeleteTableInfo("players");
    query.exec("INSERT INTO players"
               "(id, name, club, TV, age, FN, SN, FP, SP, skill, height, birthday, contractExp)"
               " SELECT"
               " id, name, club, TW, age, FN, SN, FP, SP, skill, height, birthday_FM, contract_FM"
               " FROM real.players");
    DATABASE::PrintSqlExecInfoIfErr(query);

    /*
    query.exec("SELECT id, birthday_TM, contract_TM FROM real.players;");
    DATABASE::PrintSqlExecInfoIfErr(query);
    while(query.next()){
        int cur_id = query.value(0).toInt();
        int tm_bd = query.value(1).toInt();
        int tm_contrExp = query.value(2).toInt();
        int raw_bd = DATE::rawDateFromTMDate(tm_bd);
        int raw_contrExp = DATE::rawDateFromTMDate(tm_contrExp);
        QSqlQuery updQuery(*db);
        updQuery.exec("UPDATE players SET birthday = '" + QString::number(raw_bd) +
                      "', contractExp = '" + QString::number(raw_contrExp) + "' WHERE "
                      "id = '" + QString::number(cur_id) + "';");
        DATABASE::PrintSqlExecInfoIfErr(updQuery);

    }
    */

    qDebug() << "Copying players data into dynamic database finished. Last error: " + query.lastError().text();
}

void DATABASE_DYNAMIC_DATA::FillGameData(GAME_DATA *gameData) const
{
    QList<QPair<FEDERATION*, QList<QString>>> fedsList = FillFederationsGameData(gameData);
    AttachLeaguesToFeds(fedsList, gameData);
}

QList<QPair<FEDERATION*, QList<QString>>> DATABASE_DYNAMIC_DATA::FillFederationsGameData(GAME_DATA *gameData) const
{
    QList<QPair<FEDERATION*, QList<QString>>> list;
    QSqlQuery query(*db);
    query.exec("SELECT * from federations");
    DATABASE::PrintSqlExecInfoIfErr(query);
    while(query.next()){
        //int fedId = query.value(0).toInt();
        QString name = query.value(1).toString();
        int countryId = query.value(2).toInt();
        QList<QString> leagueIdsList;
        for(int i = 3; i <= 5; ++i){
            QString curLeague = query.value(i).toString();
            if(curLeague != ""){
                leagueIdsList.push_back(curLeague);
            }
        }
        FEDERATION* curFed = new FEDERATION(countryId, name, countryId); //countryId used twise on purpose
        gameData->addFederation(curFed);
        list.push_back({curFed, leagueIdsList});
        QPixmap* flag = new QPixmap(MainWindow::GetFlagPath(curFed, "48x30"));
        curFed->setFlag(flag);
    }
    return list;
}

void DATABASE_DYNAMIC_DATA::AttachLeaguesToFeds(QList<QPair<FEDERATION*, QList<QString>>> fedsList, GAME_DATA* gameData) const
{
    for(const auto& f : fedsList){
        QList<QString> leaguesIdsList = f.second;
        FEDERATION* curFed = f.first;
        QList<LEAGUE*> leaguesList = InitLeagueList(leaguesIdsList, curFed, gameData);
        curFed->setLeagues(leaguesList);
        gameData->addLeagues(leaguesList);
    }
}

QList<LEAGUE *> DATABASE_DYNAMIC_DATA::InitLeagueList(QList<QString> &leagueIdsList,
                                                      FEDERATION* curFed, GAME_DATA *gameData) const
{
    QList<LEAGUE*> leagueList;
    QSqlQuery query(*db);
    for(int i = 0; i < leagueIdsList.size(); ++i){
        LEAGUE* curLeague = new LEAGUE();
        query.exec("SELECT name FROM leagues WHERE id = '" + leagueIdsList[i] + "';");
        DATABASE::PrintSqlExecInfoIfErr(query);
        query.next();
        QString curName = query.value(0).toString();
        int curTier = i + 1;
        curLeague->setName(curName);
        curLeague->setTier(curTier);
        curLeague->setId(leagueIdsList[i]);
        curLeague->setFederation(curFed);
        leagueList.push_back(curLeague);
    }
    for(const auto &l : leagueList){
        QList<CLUB*> clubsList = InitClubsByLeague(l, gameData);
        l->setClubList(clubsList);
        gameData->addClubs(clubsList);
    }
    return leagueList;
}

QList<CLUB *> DATABASE_DYNAMIC_DATA::InitClubsByLeague(LEAGUE* league, GAME_DATA *gameData) const
{
    QSqlQuery query(*db);
    QList<CLUB*> clubList;
    query.exec("SELECT "
               "id, name, stadiumName, stadiumCapacity, playersTV, transferBudget, prestige "
               "FROM clubs "
               "WHERE leagueId = '" + league->getId() + "';");
    DATABASE::PrintSqlExecInfoIfErr(query);
    while(query.next()){
        int curId = query.value(0).toInt();
        QString curName = query.value(1).toString();
        QString curSN = query.value(2).toString();
        int curSC = query.value(3).toInt();
        int curTV = query.value(4).toInt();
        int curTB = query.value(5).toInt();
        int curPrestige = query.value(6).toInt();

        STADIUM::NormalizeStadiumCapacity(curSC);

        CLUB* curClub = new CLUB(curId, curName, curTV, curTB, curSN, curSC, curPrestige);

        QList<PLAYER*> playersList = InitPlayersByClub(curClub, gameData);

        curClub->setPlayerList(playersList);
        curClub->setFederation(league->getFederation());
        gameData->addPlayers(playersList);
        clubList.push_back(curClub);
    }
    return clubList;
}

QList<PLAYER *> DATABASE_DYNAMIC_DATA::InitPlayersByClub(CLUB* curClub, GAME_DATA *gameData) const
{
    QMap<QPair<int, int>, PLAYER_POSITION*> positionsMap = gameData->getPositions();
    const int clubId = curClub->getId();
    QSqlQuery query(*db);
    QList<PLAYER*> playersList;
    query.exec("SELECT id, name, TV, age, FN, SN, FP, SP, skill, height, birthday, contractExp FROM players "
               "WHERE club = '" + QString::number(clubId) + "';");
    DATABASE::PrintSqlExecInfoIfErr(query);
    while(query.next()){
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
        int curBirthdayRaw = query.value(10).toInt();
        int curContractExpRaw = query.value(11).toInt();

        bool wasNormalizedTV = PLAYER::NormalizeTV(curTV);
        bool wasNormalizedAge = PLAYER::NormalizeAgeAndBirthday(curAge, curBirthdayRaw);
        if(wasNormalizedTV || wasNormalizedAge){
            curSkill = skillConvDb->CountPlayerSkill(curTV, curAge, curFPid);
        }

        PLAYER::NormalizeHeight(curH);
        if(!curContractExpRaw){
            curContractExpRaw = DEFAULT_CONTRACT_EXPIRING_DATE;
        }

        QString FFstr = gameData->getCountryMap()->getById(curFNid);
        FEDERATION* FF = gameData->implicitlyGetFederation(curFNid, FFstr);
        QString SFstr;
        FEDERATION* SF = nullptr;
        if(curSNid != 0){
            SFstr = gameData->getCountryMap()->getById(curSNid);
            SF = gameData->implicitlyGetFederation(curSNid, SFstr);
        }

        DATE curBirthday(curBirthdayRaw);
        DATE curContractExp(curContractExpRaw);

        PLAYER_POSITION::NormalizeBothPosId(curFPid, curSPid);

        /*
        if(positionsMap.find({curFPid, curSPid}) == positionsMap.end()){
            int debug = 0;
        }
        */

        PLAYER* curPlayer = new PLAYER(curId, curName, curTV, curAge, curSkill, FF,
                                       SF, positionsMap[{curFPid, curSPid}], curH, curBirthday, curContractExp);
        curPlayer->setClub(curClub);
        playersList.push_back(curPlayer);
    }
    return playersList;
}

bool DATABASE_DYNAMIC_DATA::FedIsPreLoaded(QString fedName) const
{
    for(const auto &s : preLoadedFedList){
        if(s == fedName){
            return true;
        }
    }
    return false;
}

void DATABASE_DYNAMIC_DATA::FillPreLoadedFedList()
{
    QSqlQuery query(*db);
    query.exec("SELECT name FROM federations");
    DATABASE::PrintSqlExecInfoIfErr(query);
    while(query.next()){
        preLoadedFedList.push_back(query.value(0).toString());
    }
}
