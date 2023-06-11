#include "main/mainwindow.h"
#include "ui_mainwindow.h"

//TO DO: Complete redesign of settins page to match possible user intrests

void MainWindow::SetupSettingsScene(){

    ui->stackedWidget->setCurrentIndex(SW_SETTINGS_SCENE);

    // TO DO: do it

}

//Old code of setup settings scene

/*
sceneSwitch->Switch(SETTINGS_SCENE);

ClearLay(settingsSceneMainLayout);

PushBackEmptyToLay(settingsSceneMainLayout, 2);
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

QPushButton *apiLoadButton = new QPushButton("Load data from API");
apiLoadButton->setFixedWidth(280);
apiLoadButton->setFixedHeight(100);
apiLoadButton->setStyleSheet(style);
connect(apiLoadButton, &QPushButton::clicked, this, &MainWindow::LoadAllDataFromAPI);
settingsSceneMainLayout->addWidget(apiLoadButton);

QPushButton *dbLoadButton = new QPushButton("Load data from DB");
dbLoadButton->setFixedWidth(280);
dbLoadButton->setFixedHeight(100);
dbLoadButton->setStyleSheet(style);
connect(dbLoadButton, &QPushButton::clicked, this, &MainWindow::LoadAllDataFromDB);
settingsSceneMainLayout->addWidget(dbLoadButton);

QPushButton *recountButton = new QPushButton("Re-evaluate all variables");
recountButton->setFixedHeight(100);
recountButton->setStyleSheet(style);
connect(recountButton, &QPushButton::clicked, this, &MainWindow::RecountEverything);
settingsSceneMainLayout->addWidget(recountButton);

QPushButton *saveButton = new QPushButton("Save all data");
saveButton->setFixedWidth(280);
saveButton->setFixedHeight(100);
saveButton->setStyleSheet(style);
connect(saveButton, &QPushButton::clicked, this, &MainWindow::SaveAllDataDefault);
settingsSceneMainLayout->addWidget(saveButton);

PushBackEmptyToLay(settingsSceneMainLayout, 2);
*/
