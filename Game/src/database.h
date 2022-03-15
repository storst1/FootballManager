#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include "league.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>

class DATABASE
{
public:
    DATABASE(QString& dbPath);
protected:
    void SetupConnection(QString& dbPath);
    void DeleteTableInfo(QString table_name);
protected:
    QSqlDatabase* db;
};

#endif // DATABASE_H
