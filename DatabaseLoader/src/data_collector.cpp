#include "mainwindow.h"

void MainWindow::CollectData()
{
    FillAllLeagues();

}

void MainWindow::FillAllLeagues()
{
    FillAllLeaguesWithBaseInfo();
    for(int i = 0; i < allLeagues.size(); ++i){
        QList<CLUB*> curCompClubsList = InitClubs(netManager->GatherClubsListByComp(allLeagues[i]->getId()));
    }
}

void MainWindow::FillAllLeaguesWithBaseInfo()
{
    QList<QPair<QString, int>> allLeaguesInfo = realDataDb->getAllLeagues();
    for(int i = 0; i < allLeaguesInfo.size(); ++i){
        allLeagues.push_back(new LEAGUE(allLeaguesInfo[i].first, allLeaguesInfo[i].second));
        allLeagues[i]->setName(netManager->GatherLeagueName(allLeaguesInfo[i].first));
    }
}

QList<CLUB *> MainWindow::InitClubs(QList<QString> idList)
{
    QList<CLUB*> clubsList;
    for(int i = 0; i < idList.size(); ++i){
        clubsList.push_back(new CLUB(idList[i].toInt()));
    }
    return clubsList;
}
