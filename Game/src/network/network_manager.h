#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include "network/request_buffer.h"
#include "api/api_club.h"
#include "api/api_keys.h"
#include "json/json_parser_squad.h"
#include "json/json_parser_player.h"
#include "json/json_parser_club.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QMainWindow>
#include <QEventLoop>
#include <QByteArray>

#include <string>

class NETWORK_MANAGER : public QObject
{
public:
    NETWORK_MANAGER(const QString &ApiDbPath);
    ~NETWORK_MANAGER();

    QString GatherLeagueName(const QString& leagueId);
    void SetupRequestAuth();
    void SetupRequestAuth(const QString& key);
    QVector<API_CLUB> GatherClubsListByComp(const QString& compId);
    QVector<API_PLAYER*> GatherPlayersListByClub(const int clubId);
    void FillAdditionalClubInfo(API_CLUB* club);
    void HandleRequestError();
private:
    QNetworkAccessManager* manager;
    QNetworkRequest request;
    REQUEST_BUFFER* RequestBuffer;
    API_KEYS* keyList;
};

#endif // NETWORK_MANAGER_H
