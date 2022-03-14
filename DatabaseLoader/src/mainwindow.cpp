#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetupDb();
    SetupNetworkManager();
    //allLeagues = realDataDb->getAllLeagues();
}

MainWindow::~MainWindow()
{
    delete realDataDb;
    delete netManager;
    delete ui;
    qDeleteAll(allLeagues);
}

QString MainWindow::getRealDataDbPath()
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
    qDebug() << path;
    path += "/Databases/realdata.db";
    return path;
}

void MainWindow::SetupNetworkManager()
{
    netManager = new NETWORK_MANAGER();
}

void MainWindow::SetupDb()
{
    QString dbPath = getRealDataDbPath();
    realDataDb = new DATABASE(dbPath);
}

void MainWindow::SaveAllData(QList<LEAGUE *> leagues, QList<CLUB *> clubs)
{
    realDataDb->OverrideLeaguesInfo(leagues);
    realDataDb->OverrideClubsInfo(clubs);
}

void MainWindow::on_pushButton_clicked()
{
    netManager->SetupRequestAuth();
    CollectData();
}

void MainWindow::on_pushButton_2_clicked()
{
    SaveAllData(allLeagues, allClubs);
}
