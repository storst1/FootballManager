#include "main/mainwindow.h"

void MainWindow::SetupStartingScene(){
    ClearLay();

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

    startButton = new QPushButton("New Game");
    startButton->setFixedWidth(280);
    startButton->setFixedHeight(100);
    startButton->setStyleSheet(style);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::SetupNewGameScene);
    mainLay->addWidget(startButton);

    loadButton = new QPushButton("Load Game");
    loadButton->setFixedWidth(280);
    loadButton->setFixedHeight(100);
    loadButton->setStyleSheet(style);
    mainLay->addWidget(loadButton);

    settingsButton = new QPushButton("Settings");
    settingsButton->setFixedWidth(280);
    settingsButton->setFixedHeight(100);
    settingsButton->setStyleSheet(style);
    connect(settingsButton, &QPushButton::clicked, this, &MainWindow::SetupSettingsScene);
    mainLay->addWidget(settingsButton);

    PushBackEmptyToLay(2);
}
