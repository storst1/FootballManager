#include "main/mainwindow.h"
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
    SetupCountryMap();
    SetupDb();
    SetupNetworkManager();
    LoadGameData();
    SetupUser();
    SetupEventHandler();
    SetupStartingScene();
}

MainWindow::~MainWindow()
{
    delete realDataDb;
    delete dynDataDb;
    delete skillConvDb;
    delete countryMap;
    delete netManager;
    qDeleteAll(allLeagues);
    qDeleteAll(allClubs);
    qDeleteAll(allPlayers);
    //delete gameData;
    delete ui;
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

void MainWindow::FillCountryMap()
{
    QList<QPair<int, QString>> countryList = realDataDb->GetAllCountries();
    countryMap->fillMaps(countryList);
}

void MainWindow::SetupUser()
{
    user = new USER();
}

void MainWindow::ChangeUserClub(CLUB *club)
{
    user->setClub(club);
}

QString MainWindow::EuroSym()
{
    return "€";
}

QString MainWindow::NaturalizeNum(int num)
{
    QString numStr = QString::number(num);
    int i = numStr.length() - 1;
    while(true){
        int j = i - 3;
        if(j >= 0){
            numStr.insert(j + 1, ' ');
        }
        else break;
        i = j;
    }
    //qDebug() << numStr;
    return numStr;
}

QString MainWindow::GetClubLogoPath(CLUB* club)
{
    return ":/logos/200x200/" + club->getFederation()->getName() + "/" + QString::number(club->getId()) + ".png";
}

QString MainWindow::GetFlagPath(FEDERATION *fed, QString size)
{
    return ":/flags/" + size + "/" + QString::number(fed->getId()) + ".png";
}
