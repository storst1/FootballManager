#include "database/database.h"

DATABASE::DATABASE(const QString &dbPath, const QString& connectionName)
{
    SetupConnection(dbPath, connectionName);
}

DATABASE::~DATABASE()
{
    delete db;
}

QVector<QString> DATABASE::ParseStringBy(QString& s, QChar c)
{
    QVector<QString> slist;
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

//This function prints error string in qDebug() for given @query if error
//has occured in it, otherwise does nothing
void DATABASE::PrintSqlExecInfoIfErr(QSqlQuery &query)
{
    if(query.lastError().isValid()){
        PrintSqlExecInfo(query);
    }
}

//This function prints error string in qDebug() for given @query
//without checking if error has actualy occured
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

//Deletes table with given @table_name from the database that is tied to @db connection
//If operation wasn't performed successfully, will print an error string into qDebug()
void DATABASE::DeleteTableInfo(QString table_name) const
{
    QSqlQuery query(*db);
    QString queryStatement = "DELETE FROM " + table_name;
    if(!query.exec(queryStatement)){
        qDebug() << "Table was not deleted. Error: " + query.lastError().text();
    }
}
