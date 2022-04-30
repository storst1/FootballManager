#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define EURO "€"

#include "database/database_real_data.h"
#include "database/database_skill_converter.h"
#include "database/database_dynamic_data.h"
#include "network/network_manager.h"
#include "game/data/country_map.h"
#include "game/data/game_data.h"
#include "game/user/user.h"
#include "game/data/team.h"
#include "game/data/federation.h"
#include "game/time/date.h"

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QPalette>
#include <QScreen>
#include <QGuiApplication>
#include <QFont>
#include <QScrollArea>
#include <QPixmap>
#include <QPainter>
#include <QLineEdit>
#include <QCompleter>
#include <QComboBox>

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

    //Resources methods
    static QString GetClubLogoPath(CLUB *club);
    static QString GetFlagPath(FEDERATION* fed, QString size);

    //Other
    static QString EuroSym();
    static QString NaturalizeNum(int num);
    static void drawPlayerFlag(QPixmap& flag, FEDERATION* fed1, FEDERATION* fed2);
private:
    //Window properties
    Ui::MainWindow *ui;
    int width;
    int height;

    //Game info
    GAME_DATA* gameData;
    USER* user;

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

    //Other data
    enum PlayerSortType {None, Nation, Name, Pos, Age, TV, Skill};

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
    void RecountPlayersBirthdates();
    void RecountPlayersContractExp();
    void RecountPlayersDates();
    void RecountEverything();
    void SetupCountryMap();
    void FillCountryMap();
    void LoadGameData();
    void SetupUser();
    void ChangeUserClub(CLUB* club);

    //General layout methods
    void SetupMainLay();
    void PushBackEmptyToLay(int amount = 1);
    void TakeSpaceInLay(int h);
    void TakeSpaceInLay(int h, int row, int col_amount);
    void ClearLay();
    void ClearLay(QLayout* lay);

    //Scene-dependent

    QGridLayout* mainLay;

    QGridLayout* navigationLay;
    QPushButton* navigationHomeButton;
    QPushButton* navigationTransfersButton;
    QPushButton* navigationTournamentsButton;

    void SetupNavigationLay();

    //STARTING SCENE
    QPushButton* loadButton;
    QPushButton *startButton;
    QPushButton *settingsButton;
    void SetupStartingScene();

    //NEW GAME SCENE
    int NewGameCurClubIdx = 0;
    int NewGameCurLeagueIdx = 0;

    QPushButton* leagueLeftButton;
    QPushButton* leagueRightButton;
    QLabel* leagueLabel;

    QGridLayout* clubLay;
    QPushButton* clubLeftButton;
    QPushButton* clubRightButton;
    QLabel* clubName;
    QLabel* clubLogo;
    QLabel* clubTV;
    QLabel* clubBudget;
    QLabel* clubPrestige;
    QPushButton* startNewGameButton;

    QList<LEAGUE*> allLeaguesList;

    void SetupNewGameScene();
    void NewGameNextLeague();
    void NewGamePrevLeague();
    void ChangeLeagueLabel(LEAGUE* _league);
    void ChangeClubLay(CLUB* curClub);
    QMap<QString, LEAGUE*>::iterator GetNextLeagueIter(const QMap<QString, LEAGUE*>::iterator curIter,
                                                       const QMap<QString, LEAGUE*>::iterator beginIter,
                                                       const QMap<QString, LEAGUE*>::iterator endIter);
    void NewGameNextClub();
    void NewGamePrevClub();

    //HOME SCENE
    QGridLayout* homeScenePlayersHeaderLay;
    QScrollArea* homeScenePlayersScrollArea;
    QWidget* homeScenePlayersScrollAreaWidget;
    QGridLayout* homeScenePlayersLay;
    QList<PLAYER*> homeScenePlayers;
    PlayerSortType homeSceneLastSortClicked = Pos;

    void SetupHomeScene();
    void HomeSceneAddPlayersToLay();
    void HomeSceneSortPlayersByName();
    void HomeSceneSortPlayersByPos();
    void HomeSceneSortPlayersByAge();
    void HomeSceneSortPlayersByTV();
    void HomeSceneSortPlayersBySkill();
    void ReverseHomeScenePlayers();

    //TRANSFERS SCENE
    bool transfersSceneLoaded = false;
    bool transferstSceneInsertSignal = false;
    QString transferstScenePreInsertText = "";
    QList<FEDERATION*> transfersSceneFederationsList;
    QList<FEDERATION*> transfersSceneCountryFilterCurrentContents;
    QGridLayout* transfersSceneFiltersLay;
    QGridLayout* transfersScenePlayersHeaderLay;
    QScrollArea* transfersScenePlayersScrollArea;
    QWidget* transfersScenePlayersScrollAreaWidget;
    QGridLayout* transfersScenePlayersLay;
    QList<PLAYER*> transfersScenePlayers;
    PlayerSortType transfersSceneLastSortClicked = None;
    QComboBox* transfersSceneCountryFilter;
    QCompleter* transfersSceneCountryCompleter;

    void SetupTransfersScene();
    void TransfersSceneAddPlayersToLay();
    void TransfersSceneClearNameFilter();
    QList<FEDERATION*> TransfersSceneGetCurContents();
    void TransfersSceneFillNameFilter(QList<FEDERATION*>& list);
    void TransfersSceneSetupFilters();
    void TransfersSceneSetupPlayers();

    //Settings scene
    void SetupSettingsScene();
};
#endif // MAINWINDOW_H
