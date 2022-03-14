#include "network_manager.h"

NETWORK_MANAGER::NETWORK_MANAGER()
{
    RequestBuffer = new REQUEST_BUFFER();
    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply)
    {
         if (reply->error()) {
            qDebug() << "Reply error: " + reply->errorString();
            return;
         }
         RequestBuffer->setBuffer(QString(reply->readAll()));
         qDebug() << RequestBuffer->getBufferRef();
        }
    );
}

NETWORK_MANAGER::~NETWORK_MANAGER()
{
    delete manager;
    delete RequestBuffer;
}

void NETWORK_MANAGER::SetupRequestAuth()
{
    request.setRawHeader("x-rapidapi-host", "transfermarket.p.rapidapi.com");
    request.setRawHeader("x-rapidapi-key", "b9f7af25f5msh32a9cb7f56a4119p1d835ejsnd02ec50257bf");
}

QList<QString> NETWORK_MANAGER::GatherClubsListByComp(const QString &compId)
{
    request.setUrl(QUrl("https://transfermarket.p.rapidapi.com/clubs/list-by-competition?id=" + compId));
    qDebug() << request.url().toString();
    QNetworkReply* reply = manager->get(request);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QString idJsonProperty = "\"id\":\"";
    QList<int> idxsOfId = RequestBuffer->indexOfAll(idJsonProperty);
    QList<QString> idVals = RequestBuffer->GetAllValuesFromRequestBuffer(idxsOfId, idJsonProperty.length());
    qDebug() << idVals;
    return idVals;
}

QString NETWORK_MANAGER::GatherLeagueName(const QString &leagueId)
{
    request.setUrl(QUrl("https://transfermarket.p.rapidapi.com/competitions/get-header-info?id=" + leagueId));
    qDebug() << request.url().toString();
    QNetworkReply* reply = manager->get(request);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QString nameJsonProperty = "\"competitionName\":\"";
    int idxOfName = RequestBuffer->indexOf(nameJsonProperty);
    QString name = RequestBuffer->GetValueFromRequestBuffer(idxOfName + nameJsonProperty.length());
    qDebug() << name;
    return name;
}
