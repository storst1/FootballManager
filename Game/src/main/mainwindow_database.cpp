#include "main/mainwindow.h"

void MainWindow::SetupDb()
{
    QString dbFolPath = getDbFolderPath();
    realDataDb = new DATABASE_REAL_DATA(dbFolPath + "realdata.db", "DB_REAL");
    //realDataDb->MakeBackup(dbFolPath + "backups/realdata.db");
    FillCountryMap();
    skillConvDb = new DATABASE_SKILL_CONVERTER(dbFolPath + "skill_convertation_rules.db", "DB_SKILL", 1);
    //skillConvDb->MakeBackup(dbFolPath + "backups/skill_convertation_rules.db");
    dynDataDb = new DATABASE_DYNAMIC_DATA(dbFolPath + "dynamicdata.db", "DB_DYN", skillConvDb);
    dynDataDb->CopyDataFromRealDb(dbFolPath + "realdata.db", countryMap);
}

void MainWindow::SetupEventHandler()
{
    eventHandeler = new EVENT_ARRAY();
}

void MainWindow::SaveAllData(QList<API_LEAGUE *> leagues, QList<API_CLUB *> clubs, QList<API_PLAYER *> players)
{
    realDataDb->OverwriteLeaguesInfo(leagues);
    realDataDb->OverwriteClubsInfo(clubs);
    realDataDb->OverwritePlayersInfo(players);
    //QString dbFolPath = getDbFolderPath();
    //realDataDb->MakeBackup(dbFolPath + "backups/realdata.db");
    //skillConvDb->MakeBackup(dbFolPath + "backups/skill_convertation_rules.db");
}

void MainWindow::SaveAllDataDefault()
{
    SaveAllData(allLeagues, allClubs, allPlayers);
}

void MainWindow::LoadAllDataFromAPI()
{
    netManager->SetupRequestAuth();
    CollectData();
}

void MainWindow::LoadAllDataFromDB()
{
    qDeleteAll(allPlayers);
    qDeleteAll(allLeagues);
    qDeleteAll(allClubs);
    allPlayers.clear();
    allLeagues.clear();
    allClubs.clear();

    realDataDb->SelectAllLeagues(allLeagues);
    realDataDb->SelectAllClubs(allClubs);
    realDataDb->SelectAllPlayers(allPlayers);
    qDebug() << "Loading real data from db finished";
}

void MainWindow::RecountAllSkills()
{
    for(int i = 0; i < allPlayers.size(); ++i){
        allPlayers[i]->setSkill(skillConvDb->CountPlayerSkill(allPlayers[i]));
    }
    realDataDb->OverwritePlayersSkill(allPlayers);
}

void MainWindow::RecountClubsBudgets()
{
    for(const auto &c : allClubs){
        c->countBudget();
    }
    realDataDb->OverwriteClubsBudget(allClubs);
}

void MainWindow::RecountClubsPrestige()
{
    for(const auto &c : allClubs){
        c->countPrestige();
    }
    realDataDb->OverwriteClubsPrestige(allClubs);
}

void MainWindow::RecountPlayersBirthdates()
{
    for(const auto& p : allPlayers){
        p->recountFmBirthday();
    }
    realDataDb->OverwritePlayersFmBirthdates(allPlayers);
}

void MainWindow::RecountPlayersContractExp()
{
    for(const auto& p : allPlayers){
        p->recountFmContrExp();
    }
    realDataDb->OverwritePlayersFmContractExpDates(allPlayers);
}

void MainWindow::RecountPlayersDates()
{
    RecountPlayersBirthdates();
    RecountPlayersContractExp();
}

void MainWindow::RecountEverything()
{
    RecountAllSkills();
    RecountClubsBudgets();
    RecountClubsPrestige();
    RecountPlayersDates();
}

void MainWindow::SetupCountryMap()
{

    countryMap = new COUNTRY_MAP();
}

void MainWindow::LoadGameData()
{
    gameData = new GAME_DATA(countryMap);
}
