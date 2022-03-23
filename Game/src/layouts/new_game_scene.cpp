#include "main/mainwindow.h"

void MainWindow::SetupNewGameScene()
{
    ClearLay();

    TakeSpaceInLay(150);
    QString leagueLabelStyle =
            "QLabel{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "background-image:url(:/greenLay280x100.png);"
                "font-size: 40px;"
                "font-family: Comic Sans MS;"
                "color: white;"
            "}";
    QLabel *startButton = new QLabel("League Name");
    startButton->setAlignment(Qt::AlignCenter);
    startButton->setFixedWidth(1000);
    startButton->setFixedHeight(120);
    startButton->setStyleSheet(leagueLabelStyle);
    mainLay->addWidget(startButton);

    PushBackEmptyToLay(4);

    //LoadAllDataFromAPI();
    //SaveAllData(allLeagues, allClubs, allPlayers);
    //RecountAllSkills();
}
