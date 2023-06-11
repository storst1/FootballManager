#include "main/mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::SetupStartingScene(){

    ui->stackedWidget->setCurrentIndex(SW_STARTING_SCENE);

    MoveMultipleWidgetsToFitRes({
        ui->StartingSceneLoadGame,
        ui->StartingSceneNewGame,
        ui->StartingSceneSettingsButton
    });

    ResizeMultipleWidgetsToFitRes({
        ui->StartingSceneLoadGame,
        ui->StartingSceneNewGame,
        ui->StartingSceneSettingsButton
    });

    //QString s = ui->StartingSceneLoadGame->styleSheet();
    //WIDGET_QSS_IMAGE_RESIZE resize_engine(s, tmpFilesStack);
    //ui->StartingSceneLoadGame->setStyleSheet(resize_engine.ResizeAllAndBindToQss(100, 100));
}

void MainWindow::on_StartingSceneNewGame_clicked()
{
    SetupNewGameScene();
}


void MainWindow::on_StartingSceneSettingsButton_clicked()
{
    SetupSettingsScene();
}


/*

  Old UI system for starting scene

//sceneSwitch->Switch(STARTING_SCENE);

//ClearLay(startingSceneMainLayout);

//PushBackEmptyToLay(startingSceneMainLayout, 2);

//ui->StartingSceneNewGame->setStyleSheet(style);

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
