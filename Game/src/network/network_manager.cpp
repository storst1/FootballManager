#include "network/network_manager.h"

NETWORK_MANAGER::NETWORK_MANAGER(const QString& ApiDbPath)
{
    RequestBuffer = new REQUEST_BUFFER();
    keyList = new API_KEYS(ApiDbPath);
    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply)
    {
         if (reply->error()) {
            qDebug() << "Reply error: " + reply->errorString();
            return;
         }
         //char* data = (reply->readAll()).data();
         QByteArray ReplyDataRaw = reply->readAll();
         RequestBuffer->setBuffer(ReplyDataRaw.data());
         //qDebug() << RequestBuffer->getBufferRef();
        }
    );
}

NETWORK_MANAGER::~NETWORK_MANAGER()
{
    delete manager;
    delete RequestBuffer;
    delete keyList;
}

void NETWORK_MANAGER::SetupRequestAuth()
{
    request.setRawHeader("x-rapidapi-host", "transfermarket.p.rapidapi.com");
    request.setRawHeader("x-rapidapi-key", keyList->cur().toLocal8Bit());
    qDebug() << "API key is set to " << keyList->cur();
}

void NETWORK_MANAGER::SetupRequestAuth(const QString &key)
{
    request.setRawHeader("x-rapidapi-host", "transfermarket.p.rapidapi.com");
    request.setRawHeader("x-rapidapi-key", key.toLocal8Bit());
    qDebug() << "API key is set to " << key;
}

QVector<API_CLUB> NETWORK_MANAGER::GatherClubsListByComp(const QString &compId)
{
    request.setUrl(QUrl("https://transfermarket.p.rapidapi.com/clubs/list-by-competition?id=" + compId));
    qDebug() << request.url().toString();
    QNetworkReply* reply = manager->get(request);
    QEventLoop loop;
    bool* errOccured = new bool(false);
    connect(reply, &QNetworkReply::errorOccurred, this, [this, errOccured]{
        HandleRequestError();
        *errOccured = true;
    });
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    if(*errOccured){
        return GatherClubsListByComp(compId);
    }
    QString idJsonProperty = "\"id\":\"";
    QString nameJsonProperty = "\"name\":\"";
    QVector<API_CLUB> clubList;
    QVector<int> idxsOfId = RequestBuffer->indexOfAll(idJsonProperty);
    QVector<int> idxsOfNames = RequestBuffer->indexOfAll(nameJsonProperty);
    QVector<QString> idVals = RequestBuffer->GetAllValuesFromRequestBuffer(idxsOfId, idJsonProperty.length());
    QVector<QString> nameVals = RequestBuffer->GetAllValuesFromRequestBuffer(idxsOfNames, nameJsonProperty.length());
    REQUEST_BUFFER::NormalizeValues(nameVals);
    REQUEST_BUFFER::NormalizeValues(idVals);
    //qDebug() << idVals;
    for(int i = 0; i < (int)idVals.size(); ++i){
        clubList.push_back(API_CLUB(idVals[i].toInt(), nameVals[i]));
    }
    delete errOccured;
    delete reply;
    return clubList;
}

QVector<API_PLAYER *> NETWORK_MANAGER::GatherPlayersListByClub(const int clubId)
{
    request.setUrl(QUrl("https://transfermarket.p.rapidapi.com/clubs/get-squad?id=" + QString::number(clubId)));
    qDebug() << request.url().toString();
    QNetworkReply* reply = manager->get(request);
    QEventLoop loop;
    bool* errOccured = new bool(false);
    connect(reply, &QNetworkReply::errorOccurred, this, [this, errOccured]{
        HandleRequestError();
        *errOccured = true;
    });
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    if(*errOccured){
        return GatherPlayersListByClub(clubId);
    }
    JSON_PARSER_SQUAD Squad(RequestBuffer->getBuffer());
    QVector<JSON_PARSER_PLAYER> playersInfo = Squad.getPlayersParsers();
    QVector<API_PLAYER*> players;
    for(const auto &pI : playersInfo){
        players.push_back(new API_PLAYER(pI));
        //qDebug() << pI.getName();
    }
    delete errOccured;
    return players;
}

void NETWORK_MANAGER::FillAdditionalClubInfo(API_CLUB *club)
{
    request.setUrl(QUrl("https://transfermarket.p.rapidapi.com/clubs/get-profile?id=" + club->getStrId()));
    qDebug() << request.url().toString();
    QNetworkReply* reply = manager->get(request);
    QEventLoop loop;
    bool* errOccured = new bool(false);
    connect(reply, &QNetworkReply::errorOccurred, this, [this, errOccured]{
        HandleRequestError();
        *errOccured = true;
    });
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    if(*errOccured){
        FillAdditionalClubInfo(club);
        return;
    }
    JSON_PARSER_CLUB ClubProfile(RequestBuffer->getBuffer());
    club->setStadName(ClubProfile.getStadName());
    club->setStadCap(ClubProfile.getStadCapacity());
    delete errOccured;
}

QString NETWORK_MANAGER::GatherLeagueName(const QString &leagueId)
{
    request.setUrl(QUrl("https://transfermarket.p.rapidapi.com/competitions/get-header-info?id=" + leagueId));
    qDebug() << request.url().toString();
    qDebug() << "Cur key: " << request.rawHeader("x-rapidapi-key");
    QNetworkReply* reply = manager->get(request);
    QEventLoop loop;
    bool* errOccured = new bool(false);
    connect(reply, &QNetworkReply::errorOccurred, this, [this, errOccured]{
        HandleRequestError();
        *errOccured = true;
    });
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    if(*errOccured){
        return GatherLeagueName(leagueId);
    }
    QString nameJsonProperty = "\"competitionName\":\"";
    int idxOfName = RequestBuffer->indexOf(nameJsonProperty);
    QString name = RequestBuffer->GetValueFromRequestBuffer(idxOfName + nameJsonProperty.length());
    REQUEST_BUFFER::NormalizeValue(name);
    qDebug() << name;
    delete errOccured;
    return name;
}

void NETWORK_MANAGER::HandleRequestError()
{
    qDebug() << "Error in request appeared!";
    SetupRequestAuth(keyList->next());
}
