#ifndef DATABASE_REAL_DATA_H
#define DATABASE_REAL_DATA_H

#include "database.h"

class DATABASE_REAL_DATA : public DATABASE
{
public:
    DATABASE_REAL_DATA(const QString& dbPath, const QString& connectionName);
    ~DATABASE_REAL_DATA() = default;

    QList<QPair<QString, int>> getAllLeagues();
    void OverwriteLeaguesInfo(QList<API_LEAGUE *> leaguesList);
    void OverwriteClubsInfo(QList<API_CLUB*> clubsList);
    void OverwritePlayersInfo(QList<API_PLAYER*> playersList); //does not include skill column
    void OverwritePlayersSkill(QList<API_PLAYER*> playersList);
    static QString SqlGetStringReady(QString str);
    void SelectAllLeagues(QList<API_LEAGUE *> &leagues);
    void SelectAllClubs(QList<API_CLUB*> &clubs);
    void SelectAllPlayers(QList<API_PLAYER*> &players);
    void MakeBackup(const QString& backupDbPath);
    QList<QPair<int, QString>> GetAllCountries();
private:
    void SavePlayersInfo(QList<API_PLAYER*> playersList);
    void SaveClubsInfo(QList<API_CLUB*> clubsList);
    void SaveLeaguesInfo(QList<API_LEAGUE *> leaguesList);
};

#endif // DATABASE_REAL_DATA_H
