#include "main/mainwindow.h"
#include "game/data/league.h"
#include "game/data/team.h"

void MainWindow::SetupNewGameScene()
{

    sceneSwitch->Switch(NEW_GAME_SCENE);
    ClearLay(newGameSceneMainLayout);

    QString leagueLabelStyle =
            "QLabel{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "background-image:url(:/greenLay1000x120.png);"
                "font-size: 50px;"
                "font-family: Comic Sans MS;"
                "color: white;"
            "}";

    QString leftArrowButtonStyle =
            "QPushButton{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "background-image:url(:/leftArrow120x120.png);"
            "}"
            ":hover{"
                "background-image:url(:/leftArrowHighlighted120x120.png);"
            "}";

    QString rightArrowButtonStyle =
            "QPushButton{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "background-image:url(:/rightArrow120x120.png);"
            "}"
            ":hover{"
                "background-image:url(:/rightArrowHighlighted120x120.png);"
            "}";

    QString clubNameLabelStyle =
            "QLabel{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "font-size: 35px;"
                "font-family: Comic Sans MS;"
                "color: white;"
            "}";

    QString clubInfoLabelStyle =
            "QLabel{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "font-size: 25px;"
                "font-family: Comic Sans MS;"
                "color: white;"
            "}";

    QString startButtonStyle =
            "QPushButton{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "background-image:url(:/greenLay400x120.png);"
                "font-size: 40px;"
                "font-family: Comic Sans MS;"
                "color: white;"
            "}"
            ":hover{"
                "background-image:url(:/greenLay400x120Highlighted.png);"
            "}";

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
    /*
    leagueLabel->setAlignment(Qt::AlignLeft);
    QPixmap LeagueFlagPixmap(50, 50);
    MainWindow::drawLeagueHeaderFlag(LeagueFlagPixmap, allLeaguesList[NewGameCurLeagueIdx]->getFederation());
    leagueLabel->setPixmap(LeagueFlagPixmap);
    */
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

    CLUB* curClub = (newGameAllLeaguesList[NewGameCurLeagueIdx]->getClubs())[NewGameCurClubIdx];

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
        user->setClub((newGameAllLeaguesList[NewGameCurLeagueIdx]->getClubs())[NewGameCurClubIdx]);
        qDebug() << "User chose club: " << user->getClub()->getName();
        SetupHomeScene();
        //SetupTransfersScene();
    });

    TakeSpaceInLay(newGameSceneMainLayout, 20, 4, 3);
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
    NewGameChangeLeagueLabel(newGameAllLeaguesList[NewGameCurLeagueIdx]);
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
    NewGameChangeLeagueLabel(newGameAllLeaguesList[NewGameCurLeagueIdx]);
}

void MainWindow::NewGameChangeLeagueLabel(LEAGUE *_league)
{
    newGameLeagueLabel->setText(_league->getName());
    QVector<CLUB*> clubs = _league->getClubs();
    NewGameChangeClubLay(clubs[0]);
}

void MainWindow::NewGameChangeClubLay(CLUB *curClub)
{
    newGameClubName->setText(curClub->getName());

    QString clubLogoPath = GetClubLogoPath(curClub);
    newGameClubLogo->setPixmap(QPixmap(clubLogoPath));

    newGameClubTV->setText("Total transfer value of players: " + NaturalizeNum(curClub->getTV()) + EURO);

    newGameClubBudget->setText("Club budget: " + NaturalizeNum(curClub->getBudget()) + EURO);

    newGameClubPrestige->setText("Club prestige: " + NaturalizeNum(curClub->getPrestige()));
}

void MainWindow::NewGameNextClub()
{
    QVector<CLUB*> clubs = newGameAllLeaguesList[NewGameCurLeagueIdx]->getClubs();
    ++NewGameCurClubIdx;
    if(NewGameCurClubIdx >= clubs.size()){
        NewGameCurClubIdx = 0;
    }
    NewGameChangeClubLay(clubs[NewGameCurClubIdx]);
}

void MainWindow::NewGamePrevClub()
{
    QVector<CLUB*> clubs = newGameAllLeaguesList[NewGameCurLeagueIdx]->getClubs();
    --NewGameCurClubIdx;
    if(NewGameCurClubIdx < 0){
        NewGameCurClubIdx = clubs.size() - 1;
    }
    NewGameChangeClubLay(clubs[NewGameCurClubIdx]);
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
