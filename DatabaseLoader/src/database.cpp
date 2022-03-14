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
    QString queryStatement = "INSERT INTO leagues (id, name) VALUES ";
    for(auto l : leaguesList){
        queryStatement += "('" + SqlGetStringReady(l->getId()) + "', '" + SqlGetStringReady(l->getName()) + "'), ";
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

void DATABASE::SaveClubsInfo(QList<CLUB *> clubsList)
{
    QSqlQuery query(*db);
    QString queryStatement = "INSERT INTO clubs (id, name) VALUES ";
    for(auto c : clubsList){
        queryStatement += "('" + SqlGetStringReady(c->getStrId()) + "', '" + SqlGetStringReady(c->getName()) + "'), ";
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
