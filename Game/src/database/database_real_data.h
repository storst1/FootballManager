#ifndef DATABASE_REAL_DATA_H
#define DATABASE_REAL_DATA_H

#include "database.h"

class DATABASE_REAL_DATA : public DATABASE
{
public:
    DATABASE_REAL_DATA(const QString& dbPath, const QString& connectionName);
    ~DATABASE_REAL_DATA() = default;

    QList<QPair<QString, int>> getAllLeagues() const;
    void OverwriteLeaguesInfo(QList<API_LEAGUE *>& leaguesList) const;
    void OverwriteClubsInfo(QList<API_CLUB*>& clubsList) const;
    void OverwritePlayersInfo(QList<API_PLAYER*>& playersList) const; //does not include skill column
    void OverwritePlayersSkill(QList<API_PLAYER*>& playersList) const;
    void OverwriteClubsBudget(QList<API_CLUB*>& clubsList) const;
    void OverwriteClubsPrestige(QList<API_CLUB*>& clubsList) const;
    void OverwritePlayersFmBirthdates(QList<API_PLAYER*>& playersList) const;
    void OverwritePlayersFmContractExpDates(QList<API_PLAYER*>& playersList) const;
    static QString SqlGetStringReady(QString str);
    void SelectAllLeagues(QList<API_LEAGUE *> &leagues) const;
    void SelectAllClubs(QList<API_CLUB*> &clubs) const;
    void SelectAllPlayers(QList<API_PLAYER*> &players) const;
    void MakeBackup(const QString& backupDbPath) const;
    QList<QPair<int, QString>> GetAllCountries() const;
    void SavePlayersInfo(QList<API_PLAYER*>& playersList) const;
    void SaveClubsInfo(QList<API_CLUB*>& clubsList) const;
    void SaveLeaguesInfo(QList<API_LEAGUE*>& leaguesList) const;
};

#endif // DATABASE_REAL_DATA_H
