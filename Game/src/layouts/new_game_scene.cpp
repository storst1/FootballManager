#include "main/mainwindow.h"
#include "game/data/league.h"

void MainWindow::SetupNewGameScene()
{
    ClearLay();

    dynDataDb->FillGameData(gameData);
    allLeaguesList = gameData->getLeaguesList();

    TakeSpaceInLay(105, 0, 3);
    QString leagueLabelStyle =
            "QLabel{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "background-image:url(:/greenLay1000x120.png);"
                "font-size: 40px;"
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
            "}";

    QString rightArrowButtonStyle =
            "QPushButton{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "background-image:url(:/rightArrow120x120.png);"
            "}";

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

    PushBackEmptyToLay(4);
}

void MainWindow::NewGameNextLeague()
{
    NewGameCurLeagueIdx++;
    if(NewGameCurLeagueIdx >= allLeaguesList.size()){
        NewGameCurLeagueIdx = 0;
    }
    NewGameCurClubIdx = 0;
    ChangeLeagueLabel(allLeaguesList[NewGameCurLeagueIdx]);
}

void MainWindow::NewGamePrevLeague()
{
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
    //mainLay->update();
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
