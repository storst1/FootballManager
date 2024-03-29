#ifndef DATABASE_H
#define DATABASE_H

/* Base calss for database connection */

#include "api/api_league.h"
#include "api/api_player.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QPair>
#include <QVector>
#include <QDebug>

class DATABASE
{
public:
    DATABASE(const QString& dbPath, const QString& connectionName);
    ~DATABASE();

    static QVector<QString> ParseStringBy(QString& s, QChar c);
    static void PrintSqlExecInfoIfErr(QSqlQuery& query);
    static void PrintSqlExecInfo(QSqlQuery& query);
protected:
    void SetupConnection(const QString &dbPath, const QString &connectionName);
    void DeleteTableInfo(QString table_name) const;
protected:
    QSqlDatabase* db;
};

#endif // DATABASE_H
