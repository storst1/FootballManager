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
    void OverrideClubsInfo(QList<CLUB*> clubsList);
    void OverridePlayersInfo(QList<PLAYER*> playersList);
    static QString SqlGetStringReady(QString str);
    void SelectAllLeagues(QList<LEAGUE *> &leagues);
    void SelectAllClubs(QList<CLUB*> &clubs);
    void SelectAllPlayers(QList<PLAYER*> &players);
private:
    void SetupConnection(QString& dbPath);
    void DeleteTableInfo(QString table_name);
    void SavePlayersInfo(QList<PLAYER*> playersList);
    void SaveClubsInfo(QList<CLUB*> clubsList);
    void SaveLeaguesInfo(QList<LEAGUE *> leaguesList);
private:
    QSqlDatabase* db;
};

#endif // DATABASE_H
