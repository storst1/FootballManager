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
    SetupStartingScene();
}

MainWindow::~MainWindow()
{
    delete realDataDb;
    delete netManager;
    qDeleteAll(allLeagues);
    qDeleteAll(allClubs);
    qDeleteAll(allPlayers);
    delete ui;
}

void MainWindow::SetupMainLay(){
    QPixmap background(":/backgroundCutSize.jpg");
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
    while(mainLay->count()){
        QLayoutItem* curItem = mainLay->takeAt(0);
        if(curItem->layout()){
            ClearLay(curItem->layout());
            delete curItem->layout();
        }
        if(curItem->widget()){
            delete curItem->widget();
        }
        delete curItem;
    }
}

void MainWindow::ClearLay(QLayout *lay)
{
    while(lay->count()){
        QLayoutItem* curItem = lay->takeAt(0);
        if(curItem->layout()){
            ClearLay(curItem->layout());
            delete curItem->layout();
        }
        if(curItem->widget()){
            delete curItem->widget();
        }
        delete curItem;
    }
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
    QString dbFolPath = getDbFolderPath();
    realDataDb->MakeBackup(dbFolPath + "backups/realdata.db");
    skillConvDb->MakeBackup(dbFolPath + "backups/skill_convertation_rules.db");
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
}

void MainWindow::RecountEverything()
{
    RecountAllSkills();
    RecountClubsBudgets();
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

/*
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
*/
