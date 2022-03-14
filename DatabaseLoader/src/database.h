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
    void OverrideLeaguesInfo(QList<LEAGUE *> leaguesList);
    void SaveLeaguesInfo(QList<LEAGUE *> leaguesList);
    void OverrideClubsInfo(QList<CLUB*> clubsList);
    void SaveClubsInfo(QList<CLUB*> clubsList);
    static QString SqlGetStringReady(QString str);
private:
    void SetupConnection(QString& dbPath);
    void DeleteTableInfo(QString table_name);
private:
    QSqlDatabase* db;
};

#endif // DATABASE_H
