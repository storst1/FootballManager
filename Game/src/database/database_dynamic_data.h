#ifndef DATABASE_DYNAMIC_DATA_H
#define DATABASE_DYNAMIC_DATA_H

#include "database/database.h"
#include "database/database_real_data.h"
#include "database/database_skill_converter.h"
#include "game/data/data_defs.h"
#include "game/data/country_map.h"
#include "game/data/game_data.h"

#include <QMap>

class MainWindow;

class DATABASE_DYNAMIC_DATA : public DATABASE
{
public:
    DATABASE_DYNAMIC_DATA(const QString& dbPath, const QString& connectionName, DATABASE_SKILL_CONVERTER* skillConvDb);
    ~DATABASE_DYNAMIC_DATA() = default;

    void CopyDataFromRealDb(const QString &realDbPath, COUNTRY_MAP *countryMap) const;
    void CopyFederationsTable(QSqlQuery& query, COUNTRY_MAP* countryMap) const;
    void CopyLeaguesTable(QSqlQuery &query) const;
    void CopyClubsTable(QSqlQuery &query) const;
    void CopyPlayersTable(QSqlQuery &query) const;

    void FillGameData(GAME_DATA* gameData) const;
    QVector<QPair<FEDERATION *, QVector<QString> > > FillFederationsGameData(GAME_DATA* gameData) const;
    void AttachLeaguesToFeds(QVector<QPair<FEDERATION*, QVector<QString>>> fedsList, GAME_DATA *gameData) const;

    QVector<LEAGUE*> InitLeagueList(QVector<QString> &leagueIdsList, FEDERATION *curFed, GAME_DATA *gameData) const;
    QVector<TEAM*> InitClubsByLeague(LEAGUE* league, GAME_DATA *gameData) const;
    QVector<PLAYER*> InitPlayersByClub(CLUB *curClub, GAME_DATA *gameData) const;
    bool FedIsPreLoaded(QString fedName) const;
private:
    void FillPreLoadedFedList();
private:
    DATABASE_SKILL_CONVERTER* skillConvDb;
    QVector<QString> preLoadedFedList;
};

#endif // DATABASE_DYNAMIC_DATA_H
