#include "main/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //_width = size().width();
    //_height = size().height();
    //qDebug() << _width << " " << _height;
    SetupCountryMap();
    SetupDb();
    SetupNetworkManager();
    LoadGameData();
    SetupUser();
    SetupEventHandler();
    SetupGameHandler();
    SetupMainLay();
    SetupStartingScene();

    //CompleteExtractionFromAPI();
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
    delete tmpFilesStack;
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
    QVector<QPair<int, QString>> countryList = realDataDb->GetAllCountries();
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

void MainWindow::SetupEventHandler()
{
    eventHandler = new EVENT_HANDLER(DATE(START_DATE));
}

QString MainWindow::BackgroundResource(const QString &styleSheet) const noexcept
{
    int idx = styleSheet.indexOf("background: ");
    QString path;
    for(int i = idx + 12; ; ++i){
        if(styleSheet[i] == ';'){
            break;
        }
        path += styleSheet[i];
    }
    return path;
}


QString MainWindow::ProjectDir() noexcept
{
    QString path = QFileInfo(".").absolutePath();
    QDir dir(path);
    dir.cdUp();
    return dir.path();
}

QString MainWindow::GeneralResDir() noexcept
{
    return MainWindow::ProjectDir() + "/Resources";
}

// This method is used to simply extract and immediatly save all possible data using API
// as well as recouting necessary variables by one call
void MainWindow::CompleteExtractionFromAPI()
{
    LoadAllDataFromAPI();
    SaveAllDataDefault();
    RecountEverything();
}
