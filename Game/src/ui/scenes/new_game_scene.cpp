#include "main/mainwindow.h"
#include "game/data/league.h"
#include "game/data/team.h"
#include "game/data/federation.h"
#include "ui_mainwindow.h"


void MainWindow::SetupNewGameScene()
{
    ui->stackedWidget->setCurrentIndex(SW_NEW_GAME_SCENE);

    MoveMultipleWidgetsToFitRes({
        ui->NewGameSceneClubInfoLabel,
        ui->NewGameSceneClubLogo,
        ui->NewGameSceneClubName,
        ui->NewGameSceneLeaguesComboBox,
        ui->NewGameSceneStartButton,
        ui->NewGameScenePrevClubButton,
        ui->NewGameSceneNextClubButton
    });

    ResizeMultipleWidgetsToFitRes({
        ui->NewGameSceneClubInfoLabel,
        ui->NewGameSceneClubLogo,
        ui->NewGameSceneClubName,
        ui->NewGameSceneLeaguesComboBox,
        ui->NewGameSceneStartButton,
        ui->NewGameScenePrevClubButton,
        ui->NewGameSceneNextClubButton
    });

    //Set the game up by loading all the needed data from db
    dynDataDb->FillGameData(gameData);

    //Assign related to the scene properties
    newGameAllLeaguesList = gameData->getLeaguesList();
    CLUB* curClub = static_cast<CLUB*>((newGameAllLeaguesList[NewGameCurLeagueIdx]->getTeams())[NewGameCurClubIdx]);

    //Filling up comboBox with all the retrieved leagues data
    for(const LEAGUE* league : newGameAllLeaguesList){
        QIcon flag(*league->getFederation()->getFlag());
        ui->NewGameSceneLeaguesComboBox->addItem(flag, league->getName());
    }

    NewGameSceneChangeClub(curClub);
}

void MainWindow::on_NewGameSceneLeaguesComboBox_currentIndexChanged(int index)
{
    NewGameCurLeagueIdx = index;
    LEAGUE* newLeague = newGameAllLeaguesList[index];
    QList<TEAM*> allTeams = newLeague->getTeams();
    NewGameSceneChangeClub(static_cast<CLUB*>(allTeams[0]));
    NewGameCurClubIdx = 0;
}

void MainWindow::NewGameNextLeague()
{
    if(newGameAllLeaguesList.size() == 1){
        return;
    }
    NewGameCurLeagueIdx++;
    if(NewGameCurLeagueIdx >= newGameAllLeaguesList.size()){
        NewGameCurLeagueIdx = 0;
    }
    NewGameCurClubIdx = 0;
    NewGameChangeLeagueLabel_OLD(newGameAllLeaguesList[NewGameCurLeagueIdx]);
}

void MainWindow::NewGamePrevLeague()
{
    if(newGameAllLeaguesList.size() == 1){
        return;
    }
    NewGameCurLeagueIdx--;
    if(NewGameCurLeagueIdx < 0){
        NewGameCurLeagueIdx = newGameAllLeaguesList.size() - 1;
    }
    NewGameCurClubIdx = 0;
    NewGameChangeLeagueLabel_OLD(newGameAllLeaguesList[NewGameCurLeagueIdx]);
}

void MainWindow::NewGameChangeLeagueLabel_OLD(LEAGUE *_league)
{
    newGameLeagueLabel->setText(_league->getName());
    QVector<TEAM*> team_list = _league->getTeams();
    QVector<CLUB*> clubs = CLUB::CastToClub(team_list);
    NewGameChangeClubLay_OLD(clubs[0]);
}

void MainWindow::NewGameChangeClubLay_OLD(CLUB *curClub)
{
    newGameClubName->setText(curClub->getName());

    QString clubLogoPath = GetClubLogoPath(curClub);
    newGameClubLogo->setPixmap(QPixmap(clubLogoPath));

    newGameClubTV->setText("Total transfer value of players: " + NaturalizeNum(curClub->getTV()) + EURO);

    newGameClubBudget->setText("Club budget: " + NaturalizeNum(curClub->getBudget()) + EURO);

    newGameClubPrestige->setText("Club prestige: " + NaturalizeNum(curClub->getPrestige()));
}

void MainWindow::NewGameNextClub_OLD()
{
    QVector<TEAM*> team_list = newGameAllLeaguesList[NewGameCurLeagueIdx]->getTeams();
    QVector<CLUB*> clubs = CLUB::CastToClub(team_list);
    ++NewGameCurClubIdx;
    if(NewGameCurClubIdx >= clubs.size()){
        NewGameCurClubIdx = 0;
    }
    NewGameChangeClubLay_OLD(clubs[NewGameCurClubIdx]);
}

void MainWindow::NewGamePrevClub_OLD()
{
    QVector<TEAM*> team_list = newGameAllLeaguesList[NewGameCurLeagueIdx]->getTeams();
    QVector<CLUB*> clubs = CLUB::CastToClub(team_list);
    --NewGameCurClubIdx;
    if(NewGameCurClubIdx < 0){
        NewGameCurClubIdx = clubs.size() - 1;
    }
    NewGameChangeClubLay_OLD(clubs[NewGameCurClubIdx]);
}

void MainWindow::NewGameSceneChangeClub(CLUB *newClub)
{
    ui->NewGameSceneClubName->setText(newClub->getName());
    ui->NewGameSceneClubName->setAlignment(Qt::AlignCenter);

    QString clubLogoPath = GetClubLogoPath(newClub);
    ui->NewGameSceneClubLogo->setPixmap(QPixmap(clubLogoPath));
    ui->NewGameSceneClubLogo->setAlignment(Qt::AlignCenter);

    QString ClubInfoString =
            "Total transfer value of players: " + NaturalizeNum(newClub->getTV()) + EURO + "\n" +
            "Club budget: " + NaturalizeNum(newClub->getBudget()) + EURO + "\n" +
            "Club prestige: " + NaturalizeNum(newClub->getPrestige());
    ui->NewGameSceneClubInfoLabel->setText(ClubInfoString);
    ui->NewGameSceneClubInfoLabel->setAlignment(Qt::AlignCenter);
}

void MainWindow::NewGameSceneNextClub() noexcept
{
    QVector<TEAM*> team_list = newGameAllLeaguesList[NewGameCurLeagueIdx]->getTeams();
    QVector<CLUB*> clubs = CLUB::CastToClub(team_list);
    ++NewGameCurClubIdx;
    if(NewGameCurClubIdx >= clubs.size()){
        NewGameCurClubIdx = 0;
    }
    NewGameSceneChangeClub(clubs[NewGameCurClubIdx]);
}

void MainWindow::NewGameScenePrevClub() noexcept
{
    QVector<TEAM*> team_list = newGameAllLeaguesList[NewGameCurLeagueIdx]->getTeams();
    QVector<CLUB*> clubs = CLUB::CastToClub(team_list);
    --NewGameCurClubIdx;
    if(NewGameCurClubIdx < 0){
        NewGameCurClubIdx = clubs.size() - 1;
    }
    NewGameSceneChangeClub(clubs[NewGameCurClubIdx]);
}

void MainWindow::on_NewGameScenePrevClubButton_clicked()
{
    NewGameScenePrevClub();
}

void MainWindow::on_NewGameSceneNextClubButton_clicked()
{
    NewGameSceneNextClub();
}

QMap<QString, LEAGUE*>::iterator MainWindow::NewGameGetNextLeagueIter(const QMap<QString, LEAGUE*>::iterator curIter,
                                                               const QMap<QString, LEAGUE*>::iterator beginIter,
                                                               const QMap<QString, LEAGUE*>::iterator endIter)
{
    auto newIter = curIter;
    newIter++;
    if(newIter == endIter){
        newIter = beginIter;
    }
    return newIter;
}

void MainWindow::on_NewGameSceneStartButton_clicked()
{
    user->setClub(static_cast<CLUB*>((newGameAllLeaguesList[NewGameCurLeagueIdx]->getTeams())[NewGameCurClubIdx]));
    qDebug() << "User has chosen club: " << user->getClub()->getName();
    gameHandler->StartNewSeason(START_DATE / FM_DATE_YEAR_MULT);
    gameHandler->InitBirthdaysEventsForTheFirstTime();
    SetupHomeScene();
    //SetupTransfersScene();
}

//Old UI system for new game scene
/*
sceneSwitch->Switch(NEW_GAME_SCENE);
ClearLay(newGameSceneMainLayout);

dynDataDb->FillGameData(gameData);
newGameAllLeaguesList = gameData->getLeaguesList();

TakeSpaceInLay(20, 0, 3);

newGameLeagueLeftButton = new QPushButton();
newGameLeagueLeftButton->setFixedWidth(120);
newGameLeagueLeftButton->setFixedHeight(120);
newGameLeagueLeftButton->setStyleSheet(leftArrowButtonStyle);
newGameSceneMainLayout->addWidget(newGameLeagueLeftButton, 1, 0);
newGameSceneMainLayout->setAlignment(newGameLeagueLeftButton, Qt::AlignRight);
connect(newGameLeagueLeftButton, &QPushButton::clicked, this, [this]{NewGamePrevLeague();});

newGameLeagueLabel = new QLabel(newGameAllLeaguesList[NewGameCurLeagueIdx]->getName());
leagueLabel->setAlignment(Qt::AlignLeft);
QPixmap LeagueFlagPixmap(50, 50);
MainWindow::drawLeagueHeaderFlag(LeagueFlagPixmap, allLeaguesList[NewGameCurLeagueIdx]->getFederation());
leagueLabel->setPixmap(LeagueFlagPixmap);

newGameLeagueLabel->setAlignment(Qt::AlignCenter);
newGameLeagueLabel->setFixedWidth(1000);
newGameLeagueLabel->setFixedHeight(120);
newGameLeagueLabel->setStyleSheet(leagueLabelStyle);
newGameSceneMainLayout->addWidget(newGameLeagueLabel, 1, 1);

newGameLeagueRightButton = new QPushButton();
newGameLeagueRightButton->setFixedWidth(120);
newGameLeagueRightButton->setFixedHeight(120);
newGameLeagueRightButton->setStyleSheet(rightArrowButtonStyle);
newGameSceneMainLayout->addWidget(newGameLeagueRightButton, 1, 2);
newGameSceneMainLayout->setAlignment(newGameLeagueRightButton, Qt::AlignLeft);
connect(newGameLeagueRightButton, &QPushButton::clicked, this, [this]{NewGameNextLeague();});

newGameClubLay = new QGridLayout();

CLUB* curClub = static_cast<CLUB*>((newGameAllLeaguesList[NewGameCurLeagueIdx]->getTeams())[NewGameCurClubIdx]);

newGameClubName = new QLabel(curClub->getName());
newGameClubName->setStyleSheet(clubNameLabelStyle);
newGameClubName->setFixedSize(1000, 100);
newGameClubName->setAlignment(Qt::AlignCenter);
newGameClubLay->addWidget(newGameClubName);

newGameClubLogo = new QLabel();
newGameClubLogo->setFixedSize(1000, 200);
QString clubLogoPath = GetClubLogoPath(curClub);
newGameClubLogo->setPixmap(QPixmap(clubLogoPath));
newGameClubLogo->setAlignment(Qt::AlignCenter);
newGameClubLay->addWidget(newGameClubLogo);

newGameClubTV = new QLabel("Total transfer value of players: " + NaturalizeNum(curClub->getTV()) + EURO);
newGameClubTV->setStyleSheet(clubInfoLabelStyle);
newGameClubTV->setFixedSize(1000, 60);
newGameClubTV->setAlignment(Qt::AlignCenter);
newGameClubLay->addWidget(newGameClubTV);

newGameClubBudget = new QLabel("Club budget: " + NaturalizeNum(curClub->getBudget()) + EURO);
newGameClubBudget->setStyleSheet(clubInfoLabelStyle);
newGameClubBudget->setFixedSize(1000, 60);
newGameClubBudget->setAlignment(Qt::AlignCenter);
newGameClubLay->addWidget(newGameClubBudget);

newGameClubPrestige = new QLabel("Club prestige: " + NaturalizeNum(curClub->getPrestige()));
newGameClubPrestige->setStyleSheet(clubInfoLabelStyle);
newGameClubPrestige->setFixedSize(1000, 60);
newGameClubPrestige->setAlignment(Qt::AlignCenter);
newGameClubLay->addWidget(newGameClubPrestige);

newGameSceneMainLayout->addLayout(newGameClubLay, 2, 1, Qt::AlignCenter);

newGameClubLeftButton = new QPushButton();
newGameClubLeftButton->setFixedWidth(120);
newGameClubLeftButton->setFixedHeight(120);
newGameClubLeftButton->setStyleSheet(leftArrowButtonStyle);
newGameSceneMainLayout->addWidget(newGameClubLeftButton, 2, 0);
newGameSceneMainLayout->setAlignment(newGameClubLeftButton, Qt::AlignRight);
connect(newGameClubLeftButton, &QPushButton::clicked, this, [this]{NewGamePrevClub();});

newGameClubRightButton = new QPushButton();
newGameClubRightButton->setFixedWidth(120);
newGameClubRightButton->setFixedHeight(120);
newGameClubRightButton->setStyleSheet(rightArrowButtonStyle);
newGameSceneMainLayout->addWidget(newGameClubRightButton, 2, 2);
newGameSceneMainLayout->setAlignment(newGameClubRightButton, Qt::AlignLeft);
connect(newGameClubRightButton, &QPushButton::clicked, this, [this]{NewGameNextClub();});

newGameStartNewGameButton = new QPushButton("Start game!");
newGameStartNewGameButton->setFixedSize(400, 120);
newGameStartNewGameButton->setStyleSheet(startButtonStyle);
newGameSceneMainLayout->addWidget(newGameStartNewGameButton, 3, 1, Qt::AlignCenter);
connect(newGameStartNewGameButton, &QPushButton::clicked, this, [this]{
    user->setClub(static_cast<CLUB*>((newGameAllLeaguesList[NewGameCurLeagueIdx]->getTeams())[NewGameCurClubIdx]));
    qDebug() << "User has chosen club: " << user->getClub()->getName();
    gameHandler->StartNewSeason(START_DATE / FM_DATE_YEAR_MULT);
    gameHandler->InitBirthdaysEventsForTheFirstTime();
    SetupHomeScene();
    //SetupTransfersScene();
});

TakeSpaceInLay(newGameSceneMainLayout, 20, 4, 3);

QString leftArrowButtonStyle =
            QPushButton{
                background-color: transparent;
                border: none;
                background-repeat: none;
                background: none;
                background-image:url(:/leftArrow120x120.png);
            }
            :hover{
                background-image:url(:/leftArrowHighlighted120x120.png);
            };

    QString rightArrowButtonStyle =
            QPushButton{
                background-color: transparent;
                border: none;
                background-repeat: none;
                background: none;
                background-image:url(:/rightArrow120x120.png);
            }
            :hover{
                background-image:url(:/rightArrowHighlighted120x120.png);
            };

*/
