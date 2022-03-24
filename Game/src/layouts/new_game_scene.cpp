#include "main/mainwindow.h"

void MainWindow::SetupNewGameScene()
{
    ClearLay();

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

    QPushButton* leagueLeftButton = new QPushButton();
    leagueLeftButton->setFixedWidth(120);
    leagueLeftButton->setFixedHeight(120);
    leagueLeftButton->setStyleSheet(leftArrowButtonStyle);
    mainLay->addWidget(leagueLeftButton, 1, 0);
    mainLay->setAlignment(leagueLeftButton, Qt::AlignRight);

    QLabel *startButton = new QLabel("League Name");
    startButton->setAlignment(Qt::AlignCenter);
    startButton->setFixedWidth(1000);
    startButton->setFixedHeight(120);
    startButton->setStyleSheet(leagueLabelStyle);
    mainLay->addWidget(startButton, 1, 1);

    QPushButton* leagueRightButton = new QPushButton();
    leagueRightButton->setFixedWidth(120);
    leagueRightButton->setFixedHeight(120);
    leagueRightButton->setStyleSheet(rightArrowButtonStyle);
    mainLay->addWidget(leagueRightButton, 1, 2);
    mainLay->setAlignment(leagueRightButton, Qt::AlignLeft);

    PushBackEmptyToLay(4);
}
