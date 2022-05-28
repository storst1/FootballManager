#ifndef DATABASE_REAL_DATA_H
#define DATABASE_REAL_DATA_H

#include "database/database.h"
#include "network/request_buffer.h"

class DATABASE_REAL_DATA : public DATABASE
{
public:
    DATABASE_REAL_DATA(const QString& dbPath, const QString& connectionName);
    ~DATABASE_REAL_DATA() = default;

    QVector<QPair<QString, int>> getAllLeagues() const;
    void OverwriteLeaguesInfo(QVector<API_LEAGUE *>& leaguesList) const;
    void OverwriteClubsInfo(QVector<API_CLUB*>& clubsList) const;
    void OverwritePlayersInfo(QVector<API_PLAYER*>& playersList) const; //does not include skill column
    void OverwritePlayersSkill(QVector<API_PLAYER*>& playersList) const;
    void OverwriteClubsBudget(QVector<API_CLUB*>& clubsList) const;
    void OverwriteClubsPrestige(QVector<API_CLUB*>& clubsList) const;
    void OverwritePlayersFmBirthdates(QVector<API_PLAYER*>& playersList) const;
    void OverwritePlayersFmContractExpDates(QVector<API_PLAYER*>& playersList) const;
    static QString SqlGetStringReady(QString str);
    void SelectAllLeagues(QVector<API_LEAGUE *> &leagues) const;
    void SelectAllClubs(QVector<API_CLUB*> &clubs) const;
    void SelectAllPlayers(QVector<API_PLAYER*> &players) const;
    void MakeBackup(const QString& backupDbPath) const;
    QVector<QPair<int, QString>> GetAllCountries() const;
    void SavePlayersInfo(QVector<API_PLAYER*>& playersList) const;
    void SaveClubsInfo(QVector<API_CLUB*>& clubsList) const;
    void SaveLeaguesInfo(QVector<API_LEAGUE*>& leaguesList) const;
};

#endif // DATABASE_REAL_DATA_H
