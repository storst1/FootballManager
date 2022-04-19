#include "main/mainwindow.h"

void MainWindow::CollectData()
{
    FillAllLeagues();
    for(const auto a : allLeagues){
        qDebug() << a->getName();
    }
    FillAllClubsInfo();
    FillAllPlayers();
}

void MainWindow::FillAllLeagues()
{
    FillAllLeaguesWithBaseInfo();
    for(int i = 0; i < allLeagues.size(); ++i){
        QList<API_CLUB*> curCompClubsList = InitClubs(netManager->GatherClubsListByComp(allLeagues[i]->getId()));
        for(auto cl : curCompClubsList){
            cl->setLeagueId(allLeagues[i]->getId());
        }
        allClubs.append(curCompClubsList);
    }
}

void MainWindow::FillAllLeaguesWithBaseInfo()
{
    QList<QPair<QString, int>> allLeaguesInfo = realDataDb->getAllLeagues();
    for(int i = 0; i < allLeaguesInfo.size(); ++i){
        allLeagues.push_back(new API_LEAGUE(allLeaguesInfo[i].first, allLeaguesInfo[i].second));
        allLeagues[i]->setName(netManager->GatherLeagueName(allLeaguesInfo[i].first));
    }
}

void MainWindow::FillAllPlayers()
{
    for(int i = 0; i < allClubs.size(); ++i){
        QList<API_PLAYER*> curSquad = netManager->GatherPlayersListByClub(allClubs[i]->getId());
        for(auto csq : curSquad){
            csq->setClubId(allClubs[i]->getId());
            allClubs[i]->addTV(csq->getTW());
        }
        allClubs[i]->countBudget();
        allPlayers.append(curSquad);
    }
}

void MainWindow::FillAllClubsInfo()
{
    for(int i = 0; i < allClubs.size(); ++i){
        netManager->FillAdditionalClubInfo(allClubs[i]);
    }
}

QList<API_CLUB *> MainWindow::InitClubs(QList<API_CLUB> clubList)
{
    QList<API_CLUB*> clubsList;
    for(int i = 0; i < clubList.size(); ++i){
        clubsList.push_back(new API_CLUB(clubList[i]));
    }
    return clubsList;
}
