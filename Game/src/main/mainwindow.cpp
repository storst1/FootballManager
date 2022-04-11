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
    SetupCountryMap();
    SetupDb();
    SetupNetworkManager();
    LoadGameData();
    SetupUser();
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

void MainWindow::SetupMainLay(){
    QPixmap background(":/backgroundCutSizeLessBright.jpg");
    int w = QGuiApplication::primaryScreen()->geometry().width();
    int h = QGuiApplication::primaryScreen()->geometry().height();
    qDebug() << "QGuiApplication::primaryScreen->geometry() == {" << w << ", " << h << "}";
    background = background.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    setPalette(palette);

    mainLay = new QGridLayout();
    ui->centralwidget->setLayout(mainLay);
}

void MainWindow::PushBackEmptyToLay(int amount)
{
    while(amount--){
        mainLay->addWidget(new QLabel(""));
    }
}

void MainWindow::TakeSpaceInLay(int h)
{
    QLabel* label = new QLabel("");
    label->setFixedHeight(h);
    mainLay->addWidget(label);
}

void MainWindow::TakeSpaceInLay(int h, int row, int col_amount)
{
    for(int i = 0; i < col_amount; ++i){
        QLabel* label = new QLabel("");
        label->setFixedHeight(h);
        mainLay->addWidget(label, row, i);
    }
}

void MainWindow::ClearLay()
{
    ClearLay(mainLay);
}

void MainWindow::ClearLay(QLayout *lay)
{
    QLayoutItem* curItem;
    //qDebug() << "Entered ClearLay() with lay consist of " << lay->count() << " items";
    while((curItem = lay->takeAt(0)) != nullptr){
        //qDebug() << "Entered while, i = " << i;
        if(curItem->layout() != nullptr){
            ClearLay(curItem->layout());
            //qDebug() << "Deleted lay: " << curItem->layout() << " i = " << i;
            //TO DO: Figure out if following line leads to memory leak or is it supposed to work like that
            //delete curItem->layout();
        }
        else if(curItem->widget() != nullptr){
            //qDebug() << "Deleted widget: " << curItem->widget() << " i = " << i;
            delete curItem->widget();
        }
        //qDebug() << "Trying to delete item: " << curItem;
        delete curItem;
    }
    //qDebug() << "ClearLay() finished working";
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
    FillCountryMap();
    skillConvDb = new DATABASE_SKILL_CONVERTER(dbFolPath + "skill_convertation_rules.db", "DB_SKILL", 1);
    skillConvDb->MakeBackup(dbFolPath + "backups/skill_convertation_rules.db");
    dynDataDb = new DATABASE_DYNAMIC_DATA(dbFolPath + "dynamicdata.db", "DB_DYN");
    dynDataDb->CopyDataFromRealDb(dbFolPath + "realdata.db", countryMap);
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

void MainWindow::RecountEverything()
{
    RecountAllSkills();
    RecountClubsBudgets();
    RecountClubsPrestige();
}

void MainWindow::SetupCountryMap()
{

    countryMap = new COUNTRY_MAP();
}

void MainWindow::FillCountryMap()
{
    QList<QPair<int, QString>> countryList = realDataDb->GetAllCountries();
    countryMap->fillMaps(countryList);
}

void MainWindow::LoadGameData()
{
    gameData = new GAME_DATA(countryMap);
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

void MainWindow::drawPlayerFlag(QPixmap &flag, FEDERATION *fed1, FEDERATION *fed2)
{
    if(fed1->getFlag() == nullptr){
        qDebug() << "No flag of fed with id = " << fed1->getId();
        return;
    }
    flag.fill(Qt::transparent);
    QPainter painter(&flag);
    painter.drawPixmap(0, 5, 48, 30, *fed1->getFlag());
    if(fed2 != nullptr){
        if(fed2->getFlag() == nullptr){
            qDebug() << "No flag of fed with id = " << fed2->getId();
            painter.end();
            return;
        }
        painter.drawPixmap(55, 9, 35, 22, *fed2->getFlag());
    }
    painter.end();
}

QString MainWindow::GetClubLogoPath(CLUB* club)
{
    return ":/logos/200x200/" + club->getFederation()->getName() + "/" + QString::number(club->getId()) + ".png";
}

QString MainWindow::GetFlagPath(FEDERATION *fed, QString size)
{
    return ":/flags/" + size + "/" + QString::number(fed->getId()) + ".png";
}
