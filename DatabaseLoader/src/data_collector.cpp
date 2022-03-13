#include "mainwindow.h"

void MainWindow::CollectData()
{
    QList<QPair<QString, int>> allLeaguesInfo = realDataDb->getAllLeagues();
    for(int i = 0; i < allLeaguesInfo.size(); ++i){
        allLeagues.push_back(new LEAGUE(allLeaguesInfo[i].first, allLeaguesInfo[i].second));
        allLeagues[i]->setName(GatherLeagueName(allLeaguesInfo[i].first));
    }


}

QString MainWindow::GatherLeagueName(const QString &leagueId)
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
