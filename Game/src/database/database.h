#ifndef DATABASE_H
#define DATABASE_H

#include "api/api_league.h"
#include "api/api_player.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QPair>
#include <QList>
#include <QDebug>

class DATABASE
{
public:
    DATABASE(const QString& dbPath, const QString& connectionName);
    ~DATABASE();

    static QList<QString> ParseStringBy(QString& s, QChar c);
    static void PrintSqlExecInfoIfErr(QSqlQuery& query);
    static void PrintSqlExecInfo(QSqlQuery& query);
protected:
    void SetupConnection(const QString &dbPath, const QString &connectionName);
    void DeleteTableInfo(QString table_name);
protected:
    QSqlDatabase* db;
};

#endif // DATABASE_H
