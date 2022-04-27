#include "database/database_real_data.h"

DATABASE_REAL_DATA::DATABASE_REAL_DATA(const QString &dbPath, const QString& connectionName)
    : DATABASE(dbPath, connectionName)
{
}

QList<QPair<QString, int> > DATABASE_REAL_DATA::getAllLeagues() const
{
    QSqlQuery query(*db);
    query.exec("SELECT id, league_first, league_second, league_third FROM federations;");
    DATABASE::PrintSqlExecInfoIfErr(query);
    QList<QPair<QString, int>> allLeagues;
    while(query.next()){
        int fed_id = query.value(0).toInt();
        QString fl = query.value(1).toString();
        QString sl = query.value(2).toString();
        QString tl = query.value(3).toString();
        if(fl != ""){
            allLeagues.push_back({fl, fed_id});
        }
        if(sl != ""){
            allLeagues.push_back({sl, fed_id});
        }
        if(tl != ""){
            allLeagues.push_back({tl, fed_id});
        }
    }
    return allLeagues;
}

void DATABASE_REAL_DATA::OverwriteLeaguesInfo(QList<API_LEAGUE*>& leaguesList) const
{
    DeleteTableInfo("leagues");
    SaveLeaguesInfo(leaguesList);
}

void DATABASE_REAL_DATA::SaveLeaguesInfo(QList<API_LEAGUE *> &leaguesList) const
{
    QSqlQuery query(*db);
    QString queryStatement = "INSERT INTO leagues (id, name, federation) VALUES ";
    for(auto l : leaguesList){
        queryStatement +=
                "('" + l->getId() +
                "', '" + SqlGetStringReady(l->getName()) +
                "', '" + l->getStrFed() + "'), ";
    }
    //Replace ", " with ";" at the end
    queryStatement.erase(std::prev(queryStatement.cend(), 2), queryStatement.cend());
    queryStatement += ";";
    qDebug() << queryStatement;
    query.exec(queryStatement);
    DATABASE::PrintSqlExecInfoIfErr(query);
}

void DATABASE_REAL_DATA::OverwriteClubsInfo(QList<API_CLUB *>& clubsList) const
{
    DeleteTableInfo("clubs");
    SaveClubsInfo(clubsList);
}

void DATABASE_REAL_DATA::OverwritePlayersInfo(QList<API_PLAYER *>& playersList) const
{
    DeleteTableInfo("players");
    SavePlayersInfo(playersList);
}

void DATABASE_REAL_DATA::OverwritePlayersSkill(QList<API_PLAYER *>& playersList) const
{
    QSqlQuery query(*db);
    for(auto p : playersList){
        QString queryStatement =
                "UPDATE players SET skill = '" +
                p->getStrSkill() +
                "' WHERE id = '" +
                QString::number(p->getId()) + "';";
        //qDebug() << queryStatement;
        query.exec(queryStatement);
        DATABASE::PrintSqlExecInfoIfErr(query);
    }
}

void DATABASE_REAL_DATA::OverwriteClubsBudget(QList<API_CLUB *>& clubsList) const
{
    QSqlQuery query(*db);
    for(auto c : clubsList){
        QString queryStatement =
                "UPDATE clubs SET budget = '" +
                QString::number(c->getBudget()) +
                "' WHERE id = '" +
                QString::number(c->getId()) + "';";
        //qDebug() << queryStatement;
        query.exec(queryStatement);
        DATABASE::PrintSqlExecInfoIfErr(query);
    }
}

void DATABASE_REAL_DATA::OverwriteClubsPrestige(QList<API_CLUB *> &clubsList) const
{
    QSqlQuery query(*db);
    for(auto c : clubsList){
        QString queryStatement =
                "UPDATE clubs SET prestige = '" +
                QString::number(c->getPrestige()) +
                "' WHERE id = '" +
                QString::number(c->getId()) + "';";
        //qDebug() << queryStatement;
        query.exec(queryStatement);
        DATABASE::PrintSqlExecInfoIfErr(query);
    }
}

void DATABASE_REAL_DATA::OverwritePlayersFmBirthdates(QList<API_PLAYER *> &playersList) const
{
    QSqlQuery query(*db);
    for(auto p : playersList){
        QString queryStatement =
                "UPDATE players SET birthday_FM = '" +
                QString::number(p->getFmBd()) +
                "' WHERE id = '" +
                QString::number(p->getId()) + "';";
        //qDebug() << queryStatement;
        query.exec(queryStatement);
        DATABASE::PrintSqlExecInfoIfErr(query);
    }
}

void DATABASE_REAL_DATA::OverwritePlayersFmContractExpDates(QList<API_PLAYER *> &playersList) const
{
    QSqlQuery query(*db);
    for(auto p : playersList){
        QString queryStatement =
                "UPDATE players SET contract_FM = '" +
                QString::number(p->getFmContrExp()) +
                "' WHERE id = '" +
                QString::number(p->getId()) + "';";
        //qDebug() << queryStatement;
        query.exec(queryStatement);
        DATABASE::PrintSqlExecInfoIfErr(query);
    }
}

void DATABASE_REAL_DATA::SaveClubsInfo(QList<API_CLUB *>& clubsList) const
{
    QSqlQuery query(*db);
    QString queryStatement = "INSERT INTO clubs (id, league, name, stadiumName, stadiumCapacity, playersTV, budget) VALUES ";
    for(auto c : clubsList){
        queryStatement +=
                "('" + SqlGetStringReady(c->getStrId()) +
                "', '" + c->getLeagueId() +
                "', '" + SqlGetStringReady(c->getName()) +
                "', '" + SqlGetStringReady(c->getStadName()) +
                "', '" + QString::number(c->getStadCapacity()) +
                "', '" + QString::number(c->getTV()) +
                "', '" + QString::number(c->getBudget()) +
                "'), ";
    }
    //Replace ", " with ";" at the end
    queryStatement.erase(std::prev(queryStatement.cend(), 2), queryStatement.cend());
    queryStatement += ";";
    qDebug() << queryStatement;
    query.exec(queryStatement);
    DATABASE::PrintSqlExecInfoIfErr(query);
}

QString DATABASE_REAL_DATA::SqlGetStringReady(QString str)
{
    for(int i = 0; i < str.size(); ++i){
        if(QString(str[i]) == "'"){
            str.insert(i, "'");
            ++i;
        }
    }
    return str;
}

void DATABASE_REAL_DATA::SelectAllLeagues(QList<API_LEAGUE*>& leagues) const
{
    QSqlQuery query(*db);
    query.exec("SELECT id, name, federation FROM leagues;");
    DATABASE::PrintSqlExecInfoIfErr(query);
    while(query.next()){
        QString cur_id = query.value(0).toString();
        QString cur_name = query.value(1).toString();
        int cur_fed = query.value(2).toInt();
        leagues.push_back(new API_LEAGUE(cur_id, cur_name, cur_fed));
    }
}

void DATABASE_REAL_DATA::SelectAllClubs(QList<API_CLUB *> &clubs) const
{
    QSqlQuery query(*db);
    query.exec("SELECT id, league, name, stadiumName, stadiumCapacity, playersTV FROM clubs;");
    DATABASE::PrintSqlExecInfoIfErr(query);
    while(query.next()){
        int cur_id = query.value(0).toInt();
        QString cur_league = query.value(1).toString();
        QString cur_name = query.value(2).toString();
        QString cur_sd_name = query.value(3).toString();
        int cur_sd_cap = query.value(4).toInt();
        int cur_TV = query.value(5).toInt();
        clubs.push_back(new API_CLUB(cur_id, cur_name, cur_league, cur_sd_name, cur_sd_cap, cur_TV));
    }
}

void DATABASE_REAL_DATA::SelectAllPlayers(QList<API_PLAYER *> &players) const
{
    QSqlQuery query(*db);
    query.exec("SELECT id, name, club, TW, FN, SN, age, height, FP, SP, birthday_TM, contract_TM FROM players;");
    DATABASE::PrintSqlExecInfoIfErr(query);
    while(query.next()){
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int club = query.value(2).toInt();
        int TW = query.value(3).toInt();
        int FN = query.value(4).toInt();
        int SN = query.value(5).toInt();
        int age = query.value(6).toInt();
        QString height = query.value(7).toString();
        int FP = query.value(8).toInt();
        int SP = query.value(9).toInt();
        int TM_bd = query.value(10).toInt();
        int contractExp_TM = query.value(11).toInt();
        players.push_back(new API_PLAYER(id, name, TW, FN, SN, FP, SP, height, age, club, TM_bd, contractExp_TM));
    }
}

void DATABASE_REAL_DATA::MakeBackup(const QString &backupDbPath) const
{
    //WARNING: OUTDATED METHOD, FIX BEFORE USING
    DATABASE_REAL_DATA backupDb(backupDbPath, "DB_REAL_BACKUP");
    //backupDb.db->setDatabaseName("");
    QSqlQuery backupQuery(*backupDb.db);
    backupQuery.exec("CREATE TABLE IF NOT EXISTS 'clubs' ( "
                     "'id'	INTEGER UNIQUE, "
                     "'league'	TEXT, "
                     "'name'	TEXT, "
                     "'stadiumName' TEXT, "
                     "'stadiumCapacity' INTEGER, "
                     "'playersTV' INTEGER, "
                     "'budget' INTEGER, "
                     "'prestige' INTEGER"
                     ")");
    DATABASE::PrintSqlExecInfoIfErr(backupQuery);
    backupQuery.exec("CREATE TABLE IF NOT EXISTS 'federations' ("
                     "'id'	INTEGER UNIQUE, "
                     "'country'	TEXT, "
                     "'league_first'	TEXT,"
                     "'league_second'	TEXT,"
                     "'league_third'	TEXT"
                    ")");
    DATABASE::PrintSqlExecInfoIfErr(backupQuery);
    backupQuery.exec("CREATE TABLE IF NOT EXISTS 'leagues' ("
                  "'id'	TEXT UNIQUE,"
                  "'name'	TEXT, "
                  "'federation'	INTEGER)");
    DATABASE::PrintSqlExecInfoIfErr(backupQuery);
    backupQuery.exec("CREATE TABLE IF NOT EXISTS 'players' ("
                     "'id'	INTEGER,"
                     "'name'	TEXT,"
                     "'club'	INTEGER,"
                     "'TW'	INTEGER,"
                     "'FN'	TEXT,"
                     "'SN'	TEXT,"
                     "'age'	INTEGER,"
                     "'height'	TEXT,"
                     "'FP'	INTEGER,"
                     "'SP'	INTEGER,"
                     "'skill'	REAL)");
    DATABASE::PrintSqlExecInfoIfErr(backupQuery);
    backupDb.DeleteTableInfo("federations");
    backupDb.DeleteTableInfo("clubs");
    backupDb.DeleteTableInfo("leagues");
    backupDb.DeleteTableInfo("players");

    QSqlQuery query(*db);
    query.exec("ATTACH DATABASE '" + backupDbPath + "' AS backup;");
    DATABASE::PrintSqlExecInfoIfErr(query);
    query.exec("INSERT INTO backup.federations SELECT * FROM federations");
    DATABASE::PrintSqlExecInfoIfErr(query);
    query.exec("INSERT INTO backup.clubs SELECT * FROM clubs");
    DATABASE::PrintSqlExecInfoIfErr(query);
    query.exec("INSERT INTO backup.leagues SELECT * FROM leagues");
    DATABASE::PrintSqlExecInfoIfErr(query);
    query.exec("INSERT INTO backup.players SELECT * FROM players");
    DATABASE::PrintSqlExecInfoIfErr(query);
}

QList<QPair<int, QString> > DATABASE_REAL_DATA::GetAllCountries() const
{
    QSqlQuery query(*db);
    query.exec("SELECT id, name FROM countries");
    DATABASE::PrintSqlExecInfoIfErr(query);
    QList<QPair<int, QString>> list;
    while(query.next()){
        int curId = query.value(0).toInt();
        QString curName = query.value(1).toString();
        list.push_back({curId, curName});
    }
    return list;
}

void DATABASE_REAL_DATA::SavePlayersInfo(QList<API_PLAYER *>& playersList) const
{
    QSqlQuery query(*db);
    QString queryStatement = "INSERT INTO players (id, name, club, TW, FN, SN, age, height, "
                             "FP, SP, birthday_TM, contract_TM) VALUES ";
    for(auto p : playersList){
        queryStatement +=
                "('" + QString::number(p->getId()) +
                "', '" + SqlGetStringReady(p->getName()) +
                "', '" + QString::number(p->getClubId()) +
                "', '" + QString::number(p->getTW()) +
                "', '" + QString::number(p->getFN()) +
                "', '" + QString::number(p->getSN()) +
                "', '" + QString::number(p->getAge()) +
                "', '" + p->getHeight() +
                "', '" + QString::number(p->getFP()) +
                "', '" + QString::number(p->getSP()) +
                "', '" + QString::number(p->getTmBd()) +
                "', '" + QString::number(p->getTmContrExp()) +
                "'), ";
    }
    //Replace ", " with ";" at the end
    queryStatement.erase(std::prev(queryStatement.cend(), 2), queryStatement.cend());
    queryStatement += ";";
    //qDebug() << queryStatement;
    query.exec(queryStatement);
    DATABASE::PrintSqlExecInfoIfErr(query);
}
