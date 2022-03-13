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
    QList<QPair<QString, int>> getAllLeagues();
    LEAGUE *InitLeagueByIdAndFed(QPair<QString, int> info);
private:
    void SetupConnection(QString& dbPath);
private:
    QSqlDatabase* db;
};

#endif // DATABASE_H
