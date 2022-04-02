#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database/database_real_data.h"
#include "database/database_skill_converter.h"
#include "database/database_dynamic_data.h"
#include "network/network_manager.h"
#include "game/data/country_map.h"
#include "game/data/game_data.h"

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QPalette>
#include <QScreen>
#include <QGuiApplication>
#include <QFont>

#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Database & API methods
    QString getRealDataDbPath();
    static QString getDbFolderPath();
    void SetupNetworkManager();
    void SetupDb();
    void CollectData();
    void FillAllLeagues();
    void FillAllLeaguesWithBaseInfo();
    void FillAllPlayers();
    void FillAllClubsInfo();
    QList<API_CLUB*> InitClubs(QList<API_CLUB> clubList);
    void SaveAllData(QList<API_LEAGUE*> leagues, QList<API_CLUB*> clubs, QList<API_PLAYER*> players);
    void SaveAllDataDefault();
    void LoadAllDataFromAPI();
    void LoadAllDataFromDB();
    void RecountAllSkills();
    void RecountClubsBudgets();
    void RecountClubsPrestige();
    void RecountEverything();
    void SetupCountryMap();
    void FillCountryMap();
    void LoadGameData();

    //General layout methods
    void SetupMainLay();
    void PushBackEmptyToLay(int amount = 1);
    void TakeSpaceInLay(int h);
    void TakeSpaceInLay(int h, int row, int col_amount);
    void ClearLay();
    void ClearLay(QLayout* lay);

    //Scene-dependent methods

    //Starting scene
    void SetupStartingScene();

    //New game scene
    void SetupNewGameScene();
    QMap<QString, LEAGUE*>::iterator GetNextLeagueIter(const QMap<QString, LEAGUE*>::iterator curIter,
                                                       const QMap<QString, LEAGUE*>::iterator beginIter,
                                                       const QMap<QString, LEAGUE*>::iterator endIter);

    //Settings scene
    void SetupSettingsScene();

private slots:
    /*
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    */

private:
    Ui::MainWindow *ui;
    int width;
    int height;
    QGridLayout* mainLay;

    //Real data
    DATABASE_REAL_DATA* realDataDb;
    DATABASE_SKILL_CONVERTER* skillConvDb;
    DATABASE_DYNAMIC_DATA* dynDataDb;
    COUNTRY_MAP* countryMap;

    NETWORK_MANAGER* netManager;

    QList<API_LEAGUE*> allLeagues;
    QList<API_CLUB*> allClubs;
    QList<API_PLAYER*> allPlayers;

    //Dynamic data
    std::map<int, QString> CountryIdToName;
    std::map<QString, int> CountryNameToId;

    GAME_DATA* gameData;
};
#endif // MAINWINDOW_H
