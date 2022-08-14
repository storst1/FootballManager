#include "main/mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::SetupStartingScene(){

    ui->stackedWidget->setCurrentIndex(SW_STARTING_SCENE);
    //sceneSwitch->Switch(STARTING_SCENE);

    //ClearLay(startingSceneMainLayout);

    //PushBackEmptyToLay(startingSceneMainLayout, 2);
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

    //ui->StartingSceneNewGame->setStyleSheet(style);

    /*
    startingSceneStartButton = new QPushButton("New Game");
    startingSceneStartButton->setFixedWidth(280);
    startingSceneStartButton->setFixedHeight(100);
    startingSceneStartButton->setStyleSheet(style);
    connect(startingSceneStartButton, &QPushButton::clicked, this, &MainWindow::SetupNewGameScene);
    startingSceneMainLayout->addWidget(startingSceneStartButton);

    startingSceneLoadButton = new QPushButton("Load Game");
    startingSceneLoadButton->setFixedWidth(280);
    startingSceneLoadButton->setFixedHeight(100);
    startingSceneLoadButton->setStyleSheet(style);
    startingSceneMainLayout->addWidget(startingSceneLoadButton);

    startingSceneSettingsButton = new QPushButton("Settings");
    startingSceneSettingsButton->setFixedWidth(280);
    startingSceneSettingsButton->setFixedHeight(100);
    startingSceneSettingsButton->setStyleSheet(style);
    connect(startingSceneSettingsButton, &QPushButton::clicked, this, &MainWindow::SetupSettingsScene);
    startingSceneMainLayout->addWidget(startingSceneSettingsButton);

    PushBackEmptyToLay(startingSceneMainLayout, 2);

    startingSceneSettingsButton->hide();
    startingSceneStartButton->hide();\
    */
}

void MainWindow::on_StartingSceneNewGame_clicked()
{
    SetupNewGameScene();
}
