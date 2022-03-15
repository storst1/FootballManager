#include "database.h"

DATABASE::DATABASE(QString& dbPath)
{
    SetupConnection(dbPath);
}

QList<QPair<QString, int> > DATABASE::getAllLeagues()
{
    QSqlQuery query(*db);
    query.exec("SELECT id, league_first, league_second, league_third FROM federations;");
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

void DATABASE::OverrideLeaguesInfo(QList<LEAGUE*> leaguesList)
{
    DeleteTableInfo("leagues");
    SaveLeaguesInfo(leaguesList);
}

void DATABASE::SaveLeaguesInfo(QList<LEAGUE *> leaguesList)
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
    if(!query.exec(queryStatement)){
        qDebug() << "Insert query error. Error: " + query.lastError().text();
    }
}

void DATABASE::OverrideClubsInfo(QList<CLUB *> clubsList)
{
    DeleteTableInfo("clubs");
    SaveClubsInfo(clubsList);
}

void DATABASE::OverridePlayersInfo(QList<PLAYER *> playersList)
{
    DeleteTableInfo("players");
    SavePlayersInfo(playersList);
}

void DATABASE::SaveClubsInfo(QList<CLUB *> clubsList)
{
    QSqlQuery query(*db);
    QString queryStatement = "INSERT INTO clubs (id, league, name) VALUES ";
    for(auto c : clubsList){
        queryStatement +=
                "('" + SqlGetStringReady(c->getStrId()) +
                "', '" + c->getLeagueId() +
                "', '" + SqlGetStringReady(c->getName()) + "'), ";
    }
    //Replace ", " with ";" at the end
    queryStatement.erase(std::prev(queryStatement.cend(), 2), queryStatement.cend());
    queryStatement += ";";
    qDebug() << queryStatement;
    if(!query.exec(queryStatement)){
        qDebug() << "Insert query error. Error: " + query.lastError().text();
    }
}

QString DATABASE::SqlGetStringReady(QString str)
{
    for(int i = 0; i < str.size(); ++i){
        if(QString(str[i]) == "'"){
            str.insert(i, "'");
            ++i;
        }
    }
    return str;
}

void DATABASE::SelectAllLeagues(QList<LEAGUE*>& leagues)
{
    QSqlQuery query(*db);
    query.exec("SELECT id, name, federation FROM leagues;");
    while(query.next()){
        QString cur_id = query.value(0).toString();
        QString cur_name = query.value(1).toString();
        int cur_fed = query.value(2).toInt();
        leagues.push_back(new LEAGUE(cur_id, cur_name, cur_fed));
    }
}

void DATABASE::SelectAllClubs(QList<CLUB *> &clubs)
{
    QSqlQuery query(*db);
    query.exec("SELECT id, league, name FROM clubs;");
    while(query.exec()){
        int cur_id = query.value(0).toInt();
        QString cur_league = query.value(1).toString();
        QString cur_name = query.value(2).toString();
        clubs.push_back(new CLUB(cur_id, cur_name, cur_league));
    }
}

void DATABASE::SelectAllPlayers(QList<PLAYER *> &players)
{
    QSqlQuery query(*db);
    query.exec("SELECT id, name, club, TW, FN, SN, age, height, FP, SP FROM players;");
    while(query.exec()){
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
        players.push_back(new PLAYER(id, name, TW, FN, SN, FP, SP, height, age, club));
    }
}

void DATABASE::SetupConnection(QString& dbPath)
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setDatabaseName(dbPath);
    if(!db->open()){
        qDebug() << "Database failed to open with given path " << dbPath << "! Error: " << db->lastError().text();
    }
    else{
        qDebug() << "Database was successfuly opened!";
    }
}

void DATABASE::DeleteTableInfo(QString table_name)
{
    QSqlQuery query(*db);
    QString queryStatement = "DELETE FROM " + table_name;
    if(!query.exec(queryStatement)){
        qDebug() << "Table was not deleted. Error: " + query.lastError().text();
    }
}

void DATABASE::SavePlayersInfo(QList<PLAYER *> playersList)
{
    QSqlQuery query(*db);
    QString queryStatement = "INSERT INTO players (id, name, club, TW, FN, SN, age, height, FP, SP) VALUES ";
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
                "', '" + QString::number(p->getSP()) + "'), ";
    }
    //Replace ", " with ";" at the end
    queryStatement.erase(std::prev(queryStatement.cend(), 2), queryStatement.cend());
    queryStatement += ";";
    //qDebug() << queryStatement;
    if(!query.exec(queryStatement)){
        qDebug() << "Insert query error. Error: " + query.lastError().text();
    }
}
