#ifndef DATABASE_REAL_DATA_H
#define DATABASE_REAL_DATA_H

#include "database.h"

class DATABASE_REAL_DATA : public DATABASE
{
public:
    DATABASE_REAL_DATA(QString& dbPath);
    QList<QPair<QString, int>> getAllLeagues();
    void OverrideLeaguesInfo(QList<LEAGUE *> leaguesList);
    void OverrideClubsInfo(QList<CLUB*> clubsList);
    void OverridePlayersInfo(QList<PLAYER*> playersList);
    static QString SqlGetStringReady(QString str);
    void SelectAllLeagues(QList<LEAGUE *> &leagues);
    void SelectAllClubs(QList<CLUB*> &clubs);
    void SelectAllPlayers(QList<PLAYER*> &players);
private:
    void SavePlayersInfo(QList<PLAYER*> playersList);
    void SaveClubsInfo(QList<CLUB*> clubsList);
    void SaveLeaguesInfo(QList<LEAGUE *> leaguesList);
};

#endif // DATABASE_REAL_DATA_H
