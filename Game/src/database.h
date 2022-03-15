#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include "api_league.h"
#include "api_player.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>

class DATABASE
{
public:
    DATABASE(const QString& dbPath, const QString& connectionName);
    ~DATABASE();

    static QList<QString> ParseStringBy(QString& s, QChar c);
protected:
    void SetupConnection(const QString &dbPath, const QString &connectionName);
    void DeleteTableInfo(QString table_name);
protected:
    QSqlDatabase* db;
};

#endif // DATABASE_H
