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
