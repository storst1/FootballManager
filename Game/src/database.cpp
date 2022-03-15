#include "database.h"

DATABASE::DATABASE(QString& dbPath)
{
    SetupConnection(dbPath);
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
