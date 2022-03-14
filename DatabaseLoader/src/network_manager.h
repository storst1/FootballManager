#pragma once
#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include "request_buffer.h"
#include "club.h"

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
    NETWORK_MANAGER();
    ~NETWORK_MANAGER();

    QString GatherLeagueName(const QString& leagueId);
    void SetupRequestAuth();
    QList<CLUB> GatherClubsListByComp(const QString& compId);
private:
    QNetworkAccessManager* manager;
    QNetworkRequest request;
    REQUEST_BUFFER* RequestBuffer;
};

#endif // NETWORK_MANAGER_H
