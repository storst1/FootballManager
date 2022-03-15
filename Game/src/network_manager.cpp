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
         //char* data = (reply->readAll()).data();
         RequestBuffer->setBuffer(reply->readAll().data());
         /*
         for (int i = 0; i < s.size(); i++) {
             if (s[i] == 'é')
             {
                 // erase function to erase
                 // the character
                 s.erase(i, 1);
                 i--;
             }
         }
         */
         /*
         for(int i = 0; i < rawData.size(); ++i) {
             QChar qc = rawData.at(i);
             unsigned char c = *(unsigned char*)(&qc);
             if(c >= 127) {
                 result.append("?");
             }
             else if (QChar(c).isPrint()) {
                 result.append(QChar(c));
             }
         }
         */

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
    request.setRawHeader("x-rapidapi-key", "12032aa377msh46fb0a42a344ab2p1ebf1bjsn370bc4f86b95");
}

QList<CLUB> NETWORK_MANAGER::GatherClubsListByComp(const QString &compId)
{
    request.setUrl(QUrl("https://transfermarket.p.rapidapi.com/clubs/list-by-competition?id=" + compId));
    qDebug() << request.url().toString();
    QNetworkReply* reply = manager->get(request);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QString idJsonProperty = "\"id\":\"";
    QString nameJsonProperty = "\"name\":\"";
    QList<CLUB> clubList;
    QList<int> idxsOfId = RequestBuffer->indexOfAll(idJsonProperty);
    QList<int> idxsOfNames = RequestBuffer->indexOfAll(nameJsonProperty);
    QList<QString> idVals = RequestBuffer->GetAllValuesFromRequestBuffer(idxsOfId, idJsonProperty.length());
    QList<QString> nameVals = RequestBuffer->GetAllValuesFromRequestBuffer(idxsOfNames, nameJsonProperty.length());
    REQUEST_BUFFER::NormalizeValues(nameVals);
    REQUEST_BUFFER::NormalizeValues(idVals);
    //qDebug() << idVals;
    for(int i = 0; i < (int)idVals.size(); ++i){
        clubList.push_back(CLUB(idVals[i].toInt(), nameVals[i]));
    }
    return clubList;
}

QList<PLAYER *> NETWORK_MANAGER::GatherPlayersListByClub(const int clubId)
{
    request.setUrl(QUrl("https://transfermarket.p.rapidapi.com/clubs/get-squad?id=" + QString::number(clubId)));
    qDebug() << request.url().toString();
    QNetworkReply* reply = manager->get(request);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    JSON_PARSER_SQUAD Squad(RequestBuffer->getBuffer());
    QList<JSON_PARSER_PLAYER> playersInfo = Squad.getPlayersParsers();
    QList<PLAYER*> players;
    for(auto pI : playersInfo){
        players.push_back(new PLAYER(pI));
        qDebug() << pI.getName();
    }
    return players;
    /*
    QString nameJsonProperty = "\"competitionName\":\"";
    int idxOfName = RequestBuffer->indexOf(nameJsonProperty);
    QString name = RequestBuffer->GetValueFromRequestBuffer(idxOfName + nameJsonProperty.length());
    */
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