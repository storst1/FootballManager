#include "main/mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::SetupStartingScene(){

    PushBackEmptyToLay(2);
    QString style =
            "QPushButton{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "background-image:url(:/greenLay280x100.png);"
                "font-size: 22px;"
                "font-family: Comic Sans MS;"
                "color: white;"
            "}"
            ":hover{"
                "background-image:url(:/greenLay280x100Highlighted.png);"
            "}";

    startingSceneStartButton = new QPushButton("New Game");
    startingSceneStartButton->setFixedWidth(280);
    startingSceneStartButton->setFixedHeight(100);
    startingSceneStartButton->setStyleSheet(style);
    connect(startingSceneStartButton, &QPushButton::clicked, this, &MainWindow::SetupNewGameScene);
    mainLay->addWidget(startingSceneStartButton);

    startingSceneLoadButton = new QPushButton("Load Game");
    startingSceneLoadButton->setFixedWidth(280);
    startingSceneLoadButton->setFixedHeight(100);
    startingSceneLoadButton->setStyleSheet(style);
    mainLay->addWidget(startingSceneLoadButton);

    startingSceneSettingsButton = new QPushButton("Settings");
    startingSceneSettingsButton->setFixedWidth(280);
    startingSceneSettingsButton->setFixedHeight(100);
    startingSceneSettingsButton->setStyleSheet(style);
    connect(startingSceneSettingsButton, &QPushButton::clicked, this, &MainWindow::SetupSettingsScene);
    mainLay->addWidget(startingSceneSettingsButton);

    PushBackEmptyToLay(2);
    ui->centralwidget->setLayout(mainLay);
}
