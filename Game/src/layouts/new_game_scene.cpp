#include "main/mainwindow.h"
#include "game/data/league.h"
#include "game/data/team.h"

void MainWindow::SetupNewGameScene()
{
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

    ClearLay();

    dynDataDb->FillGameData(gameData);
    allLeaguesList = gameData->getLeaguesList();

    TakeSpaceInLay(20, 0, 3);

    leagueLeftButton = new QPushButton();
    leagueLeftButton->setFixedWidth(120);
    leagueLeftButton->setFixedHeight(120);
    leagueLeftButton->setStyleSheet(leftArrowButtonStyle);
    mainLay->addWidget(leagueLeftButton, 1, 0);
    mainLay->setAlignment(leagueLeftButton, Qt::AlignRight);
    connect(leagueLeftButton, &QPushButton::clicked, this, [this]{NewGamePrevLeague();});

    leagueLabel = new QLabel(allLeaguesList[NewGameCurLeagueIdx]->getName());
    leagueLabel->setAlignment(Qt::AlignCenter);
    leagueLabel->setFixedWidth(1000);
    leagueLabel->setFixedHeight(120);
    leagueLabel->setStyleSheet(leagueLabelStyle);
    mainLay->addWidget(leagueLabel, 1, 1);

    leagueRightButton = new QPushButton();
    leagueRightButton->setFixedWidth(120);
    leagueRightButton->setFixedHeight(120);
    leagueRightButton->setStyleSheet(rightArrowButtonStyle);
    mainLay->addWidget(leagueRightButton, 1, 2);
    mainLay->setAlignment(leagueRightButton, Qt::AlignLeft);
    connect(leagueRightButton, &QPushButton::clicked, this, [this]{NewGameNextLeague();});

    clubLay = new QGridLayout();

    CLUB* curClub = (allLeaguesList[NewGameCurLeagueIdx]->getClubs())[NewGameCurClubIdx];

    clubName = new QLabel(curClub->getName());
    clubName->setStyleSheet(clubNameLabelStyle);
    clubName->setFixedSize(1000, 100);
    clubName->setAlignment(Qt::AlignCenter);
    clubLay->addWidget(clubName);

    clubLogo = new QLabel();
    clubLogo->setFixedSize(1000, 200);
    QString clubLogoPath = GetClubLogoPath(curClub);
    clubLogo->setPixmap(QPixmap(clubLogoPath));
    clubLogo->setAlignment(Qt::AlignCenter);
    clubLay->addWidget(clubLogo);

    clubTV = new QLabel("Total transfer value of players: " + NaturalizeNum(curClub->getTV()) + EURO);
    clubTV->setStyleSheet(clubInfoLabelStyle);
    clubTV->setFixedSize(1000, 60);
    clubTV->setAlignment(Qt::AlignCenter);
    clubLay->addWidget(clubTV);

    clubBudget = new QLabel("Club budget: " + NaturalizeNum(curClub->getBudget()) + EURO);
    clubBudget->setStyleSheet(clubInfoLabelStyle);
    clubBudget->setFixedSize(1000, 60);
    clubBudget->setAlignment(Qt::AlignCenter);
    clubLay->addWidget(clubBudget);

    clubPrestige = new QLabel("Club prestige: " + NaturalizeNum(curClub->getPrestige()));
    clubPrestige->setStyleSheet(clubInfoLabelStyle);
    clubPrestige->setFixedSize(1000, 60);
    clubPrestige->setAlignment(Qt::AlignCenter);
    clubLay->addWidget(clubPrestige);

    mainLay->addLayout(clubLay, 2, 1, Qt::AlignCenter);

    clubLeftButton = new QPushButton();
    clubLeftButton->setFixedWidth(120);
    clubLeftButton->setFixedHeight(120);
    clubLeftButton->setStyleSheet(leftArrowButtonStyle);
    mainLay->addWidget(clubLeftButton, 2, 0);
    mainLay->setAlignment(clubLeftButton, Qt::AlignRight);
    connect(clubLeftButton, &QPushButton::clicked, this, [this]{NewGamePrevClub();});

    clubRightButton = new QPushButton();
    clubRightButton->setFixedWidth(120);
    clubRightButton->setFixedHeight(120);
    clubRightButton->setStyleSheet(rightArrowButtonStyle);
    mainLay->addWidget(clubRightButton, 2, 2);
    mainLay->setAlignment(clubRightButton, Qt::AlignLeft);
    connect(clubRightButton, &QPushButton::clicked, this, [this]{NewGameNextClub();});

    startNewGameButton = new QPushButton("Start game!");
    startNewGameButton->setFixedSize(400, 120);
    startNewGameButton->setStyleSheet(startButtonStyle);
    mainLay->addWidget(startNewGameButton, 3, 1, Qt::AlignCenter);
    connect(startNewGameButton, &QPushButton::clicked, this, [this]{
        user->setClub((allLeaguesList[NewGameCurLeagueIdx]->getClubs())[NewGameCurClubIdx]);
        qDebug() << "User chose club: " << user->getClub()->getName();
        SetupHomeScene();
    });

    TakeSpaceInLay(20, 7, 3);
}

void MainWindow::NewGameNextLeague()
{
    if(allLeaguesList.size() == 1){
        return;
    }
    NewGameCurLeagueIdx++;
    if(NewGameCurLeagueIdx >= allLeaguesList.size()){
        NewGameCurLeagueIdx = 0;
    }
    NewGameCurClubIdx = 0;
    ChangeLeagueLabel(allLeaguesList[NewGameCurLeagueIdx]);
}

void MainWindow::NewGamePrevLeague()
{
    if(allLeaguesList.size() == 1){
        return;
    }
    NewGameCurLeagueIdx--;
    if(NewGameCurLeagueIdx < 0){
        NewGameCurLeagueIdx = allLeaguesList.size() - 1;
    }
    NewGameCurClubIdx = 0;
    ChangeLeagueLabel(allLeaguesList[NewGameCurLeagueIdx]);
}

void MainWindow::ChangeLeagueLabel(LEAGUE *_league)
{
    leagueLabel->setText(_league->getName());
    QList<CLUB*> clubs = _league->getClubs();
    ChangeClubLay(clubs[0]);
}

void MainWindow::ChangeClubLay(CLUB *curClub)
{
    clubName->setText(curClub->getName());

    QString clubLogoPath = GetClubLogoPath(curClub);
    clubLogo->setPixmap(QPixmap(clubLogoPath));

    clubTV->setText("Total transfer value of players: " + NaturalizeNum(curClub->getTV()) + EURO);

    clubBudget->setText("Club budget: " + NaturalizeNum(curClub->getBudget()) + EURO);

    clubPrestige->setText("Club prestige: " + NaturalizeNum(curClub->getPrestige()));
}

void MainWindow::NewGameNextClub()
{
    QList<CLUB*> clubs = allLeaguesList[NewGameCurLeagueIdx]->getClubs();
    ++NewGameCurClubIdx;
    if(NewGameCurClubIdx >= clubs.size()){
        NewGameCurClubIdx = 0;
    }
    ChangeClubLay(clubs[NewGameCurClubIdx]);
}

void MainWindow::NewGamePrevClub()
{
    QList<CLUB*> clubs = allLeaguesList[NewGameCurLeagueIdx]->getClubs();
    --NewGameCurClubIdx;
    if(NewGameCurClubIdx < 0){
        NewGameCurClubIdx = clubs.size() - 1;
    }
    ChangeClubLay(clubs[NewGameCurClubIdx]);
}

QMap<QString, LEAGUE*>::iterator MainWindow::GetNextLeagueIter(const QMap<QString, LEAGUE*>::iterator curIter,
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
