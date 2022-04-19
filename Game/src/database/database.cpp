#include "database/database.h"

DATABASE::DATABASE(const QString &dbPath, const QString& connectionName)
{
    SetupConnection(dbPath, connectionName);
}

DATABASE::~DATABASE()
{
    delete db;
}

QList<QString> DATABASE::ParseStringBy(QString& s, QChar c)
{
    QList<QString> slist;
    QString cur = "";
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == c){
            slist.push_back(cur);
            cur.clear();
            continue;
        }
        cur += s[i];
    }
    if(!cur.isEmpty()){
        slist.push_back(cur);
    }
    return slist;
}

void DATABASE::PrintSqlExecInfoIfErr(QSqlQuery &query)
{
    if(query.lastError().isValid()){
        PrintSqlExecInfo(query);
    }
}

void DATABASE::PrintSqlExecInfo(QSqlQuery &query)
{
    qDebug() << query.executedQuery() << " . Error: " << query.lastError().text();
}

void DATABASE::SetupConnection(const QString& dbPath, const QString& connectionName)
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", connectionName));
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
