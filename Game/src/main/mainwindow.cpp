#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    width = size().width();
    height = size().height();
    qDebug() << width << " " << height;
    SetupMainLay();
    SetupDb();
    SetupNetworkManager();
    SetupStartingScene();
}

MainWindow::~MainWindow()
{
    delete realDataDb;
    delete netManager;
    delete ui;
    qDeleteAll(allLeagues);
}

void MainWindow::SetupMainLay(){
    QPixmap background(":/background7.jpg");
    background = background.scaled(1600, 900, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    setPalette(palette);

    mainLay = new QGridLayout();
    ui->centralwidget->setLayout(mainLay);
}

QString MainWindow::getRealDataDbPath()
{
    QString path = getDbFolderPath();
    qDebug() << path;
    path += "/Databases/realdata.db";
    return path;
}

QString MainWindow::getDbFolderPath()
{
    qDebug() << qApp->applicationDirPath();
    QString path = qApp->applicationDirPath();
    int cnt = 0;
    int i = path.length() - 1;
    while(cnt < 3){
        if(path[i] == '/'){
            ++cnt;
        }
        --i;
    }
    path.erase(path.cbegin() + i + 1, path.cend());
    return path + "/Databases/";
}

void MainWindow::SetupNetworkManager()
{
    netManager = new NETWORK_MANAGER(getDbFolderPath() + "api_keys.db");
}

void MainWindow::SetupDb()
{
    QString dbFolPath = getDbFolderPath();
    realDataDb = new DATABASE_REAL_DATA(dbFolPath + "realdata.db", "DB_REAL");
    realDataDb->MakeBackup(dbFolPath + "backups/realdata.db");
    skillConvDb = new DATABASE_SKILL_CONVERTER(dbFolPath + "skill_convertation_rules.db", "DB_SKILL", 1);
    skillConvDb->MakeBackup(dbFolPath + "backups/skill_convertation_rules.db");
}

void MainWindow::SaveAllData(QList<API_LEAGUE *> leagues, QList<API_CLUB *> clubs, QList<API_PLAYER *> players)
{
    realDataDb->OverwriteLeaguesInfo(leagues);
    realDataDb->OverwriteClubsInfo(clubs);
    realDataDb->OverwritePlayersInfo(players);
    QString dbFolPath = getDbFolderPath();
    realDataDb->MakeBackup(dbFolPath + "backups/realdata.db");
    skillConvDb->MakeBackup(dbFolPath + "backups/skill_convertation_rules.db");
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

void MainWindow::on_pushButton_clicked()
{
    LoadAllDataFromAPI();
}

void MainWindow::on_pushButton_2_clicked()
{
    SaveAllData(allLeagues, allClubs, allPlayers);
}

void MainWindow::on_pushButton_3_clicked()
{
    LoadAllDataFromDB();
}


void MainWindow::on_pushButton_4_clicked()
{
    for(int i = 0; i < allPlayers.size(); ++i){
        allPlayers[i]->setSkill(skillConvDb->CountPlayerSkill(allPlayers[i]));
    }
    realDataDb->OverwritePlayersSkill(allPlayers);
}

