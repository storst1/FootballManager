#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define EURO "€"

#include "scenes/operational/scenes_defs.h"

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
#include "game/data/player_search_filter.h"
#include "game/events/event_handler.h"
#include "game/events/event_birthday.h"
#include "game/game.h"
#include "scenes/operational/scene_switch.h"

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
#include <QVariant>
#include <QScrollBar>
#include <QDebug>
#include <QStackedWidget>
#include <QVariant>

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
    static void drawLeagueHeaderFlag(QPixmap& flag, FEDERATION* fed);

private slots:
    void on_StartingSceneNewGame_clicked();
    void on_NewGameSceneLeaguesComboBox_currentIndexChanged(int index);

    void on_NewGameScenePrevClubButton_clicked();

    void on_NewGameSceneNextClubButton_clicked();

private:
    //Window properties
    Ui::MainWindow *ui;
    int _width;
    int _height;

    //Game info
    GAME_DATA* gameData;
    USER* user;
    EVENT_HANDLER* eventHandler;
    GAME* gameHandler;

    //Real data
    DATABASE_REAL_DATA* realDataDb;
    DATABASE_SKILL_CONVERTER* skillConvDb;
    DATABASE_DYNAMIC_DATA* dynDataDb;
    COUNTRY_MAP* countryMap;

    NETWORK_MANAGER* netManager;

    QVector<API_LEAGUE*> allLeagues;
    QVector<API_CLUB*> allClubs;
    QVector<API_PLAYER*> allPlayers;

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
    void SetupEventHandler();
    void CollectData();
    void FillAllLeagues();
    void FillAllLeaguesWithBaseInfo();
    void FillAllPlayers();
    void FillAllClubsInfo();
    QVector<API_CLUB*> InitClubs(QVector<API_CLUB> clubList);
    void SaveAllData(QVector<API_LEAGUE*> leagues, QVector<API_CLUB*> clubs, QVector<API_PLAYER*> players);
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
    void SetupGameHandler();
    void SetupUser();
    void ChangeUserClub(CLUB* club);

    //General layout methods
    void SetupMainLay();
    void PushBackEmptyToLay(int amount = 1);
    void PushBackEmptyToLay(QGridLayout* lay, int amount = 1);
    void TakeSpaceInLay(int h);
    void TakeSpaceInLay(QGridLayout* lay, int h);
    void TakeSpaceInLay(int h, int row, int col_amount);
    void TakeSpaceInLay(QGridLayout* lay, int h, int row, int col_amount);
    void ClearLay();
    void ClearLay(QGridLayout *lay);
    static QLabel* NewTrashPtr();

    void MoveWidgetToFitRes(QWidget* widget) noexcept;
    void MoveAllChildWidgetsToFitRes(QWidget* widget) noexcept;
    //void MoveMultipleWidgetsToFitRes(QWidget* widgets...);
    void MoveMultipleWidgetsToFitRes(std::initializer_list<QWidget*> widgets);
    void ResizeWidgetToFitRes(QWidget* widget);
    void ResizePB(QPushButton* PB, float x_mult, float y_mult);
    void ResizeComboBox(QComboBox* CB, float x_mult, float y_mult);
    void ResizeLabel(QLabel* label, float x_mult, float y_mult);
    void ResizeGeneralWidget(QWidget* widget, float x_mult, float y_mult);
    void ResizeMultipleWidgetsToFitRes(std::initializer_list<QWidget*> widgets);

    QString BackgroundResource(const QString& styleSheet) const noexcept;

    //Scene-dependent stuff

    QVector<int> allScenes = {
        STARTING_SCENE,
        SETTINGS_SCENE,
        NEW_GAME_SCENE,
        HOME_SCENE,
        TRANSFERS_SCENE,
        SQUAD_SCENE
    };

    QGridLayout* mainLay;
    QStackedWidget* mainWidget;

    SCENE_SWITCH* sceneSwitch;

    QGridLayout* navigationLay = nullptr;
    QPushButton* navigationHomeButton = nullptr;
    QPushButton* navigationTransfersButton = nullptr;
    QPushButton* navigationTournamentsButton = nullptr;

    void InitAllScenes();
    QWidget* InitScene(int scene);

    void SetupNavigationLay();

    //STARTING SCENE
    QWidget* startingSceneMainWidget;
    QGridLayout* startingSceneMainLayout;
    QPushButton* startingSceneLoadButton;
    QPushButton* startingSceneStartButton;
    QPushButton* startingSceneSettingsButton;
    void SetupStartingScene();

    //NEW GAME SCENE
    QWidget* newGameSceneMainWidget;
    QGridLayout* newGameSceneMainLayout;

    int NewGameCurClubIdx = 0;
    int NewGameCurLeagueIdx = 0;

    QPushButton* newGameLeagueLeftButton;
    QPushButton* newGameLeagueRightButton;
    QLabel* newGameLeagueLabel;

    QGridLayout* newGameClubLay;
    QPushButton* newGameClubLeftButton;
    QPushButton* newGameClubRightButton;
    QLabel* newGameClubName;
    QLabel* newGameClubLogo;
    QLabel* newGameClubTV;
    QLabel* newGameClubBudget;
    QLabel* newGameClubPrestige;
    QPushButton* newGameStartNewGameButton;

    QVector<LEAGUE*> newGameAllLeaguesList;

    void SetupNewGameScene();
    void NewGameNextLeague();
    void NewGamePrevLeague();
    void NewGameChangeLeagueLabel_OLD(LEAGUE* _league);
    void NewGameChangeClubLay_OLD(CLUB* curClub);
    QMap<QString, LEAGUE*>::iterator NewGameGetNextLeagueIter(const QMap<QString, LEAGUE*>::iterator curIter,
                                                       const QMap<QString, LEAGUE*>::iterator beginIter,
                                                       const QMap<QString, LEAGUE*>::iterator endIter);
    void NewGameNextClub_OLD();
    void NewGamePrevClub_OLD();
    void NewGameSceneChangeClub(CLUB* newClub);
    void NewGameSceneNextClub() noexcept;
    void NewGameScenePrevClub() noexcept;

    //HOME SCENE
    QWidget* homeSceneMainWidget;
    QGridLayout* homeSceneMainLayout;
    QGridLayout* homeScenePlayersHeaderLay;
    QScrollArea* homeScenePlayersScrollArea;
    QWidget* homeScenePlayersScrollAreaWidget;
    QGridLayout* homeScenePlayersLay;
    QVector<PLAYER*> homeScenePlayers;
    PlayerSortType homeSceneLastSortClicked = Pos;
    QPushButton* homeSceneContinueButton;
    QLabel* homeSceneCalendarBar = nullptr;
    QPushButton* homeSceneSquadButton;

    void SetupHomeScene();
    void HomeSceneAddPlayersToLay();
    void HomeSceneSortPlayersByName();
    void HomeSceneSortPlayersByPos();
    void HomeSceneSortPlayersByAge();
    void HomeSceneSortPlayersByTV();
    void HomeSceneSortPlayersBySkill();
    void HomeSceneReversePlayers();
    void HomeSceneSetupCalendarBar(DATE curDate);
    void HomeSceneUpdateCalendarBar(DATE curDate);
    void HomeSceneDrawDayOnCalendarBar(DATE date, int row, QPainter &painter);

    //TRANSFERS SCENE
    QWidget* transfersSceneMainWidget;
    QGridLayout* transfersSceneMainLayout;
    bool transfersSceneLoaded = false;
    bool transferstSceneInsertSignal = false;
    QString transferstScenePreInsertText = "";
    QVector<FEDERATION*> transfersSceneFederationsList;
    QVector<FEDERATION*> transfersSceneCountryFilterCurrentContents;
    QGridLayout* transfersSceneFiltersLay;
    QGridLayout* transfersScenePlayersHeaderLay;
    QScrollArea* transfersScenePlayersScrollArea;
    QWidget* transfersScenePlayersScrollAreaWidget;
    QGridLayout* transfersScenePlayersLay;
    QVector<PLAYER*> transfersScenePlayers;
    PlayerSortType transfersSceneLastSortClicked = None;
    QCompleter* transfersSceneCountryCompleter;
    QPushButton* transfersSceneSearchButton;
    QComboBox* transfersSceneCountryFilter;
    QComboBox* transfersScenePosFilter;
    QComboBox* transfersSceneSecondCountryFilter;
    QComboBox* transfersSceneSecondPosFilter;
    QLineEdit* transfersSceneNameFilter;
    QLineEdit* transfersSceneMinAgeFilter;
    QLineEdit* transfersSceneMaxAgeFilter;
    QLineEdit* transfersSceneMinSkillFilter;
    QLineEdit* transfersSceneMaxSkillFilter;

    void SetupTransfersScene();
    void TransfersSceneAddPlayersToLay();
    QVector<FEDERATION*> TransfersSceneGetCurContents();
    void TransfersSceneFillCountryFilter(QVector<FEDERATION*>& list);
    void TransfersSceneFillSecondCountryFilter(QVector<FEDERATION*>& list);
    void TransfersSceneSetupFilters();
    void TransfersSceneSetupPlayers();
    void TransfersSceneUpdatePlayersList();
    PLAYER_SEARCH_FILTER TransfersSceneGetCurrentFilter() const;
    void TransfersSceneFillPosFilter();
    void TransfersSceneFillSecondPosFilter();
    void TransfersSceneFillBothPosFilters();
    void TransfersSceneSetupNameFilter();
    void TransfersSceneSetupCountryFilter();
    void TransfersSceneSetupSecondCountryFilter();
    void TransfersSceneSetupPosFilter();
    void TransfersSceneSetupSecondPosFilter();
    void TransfersSceneSetupAgeFilter();
    void TransfersSceneSetupSkillFilter();

    //SQUAD SCENE
    void SetupSquadScene();

    //SETTINGS SCENE
    QWidget* settingsSceneMainWidget;
    QGridLayout* settingsSceneMainLayout;
    void SetupSettingsScene();
};
#endif // MAINWINDOW_H
