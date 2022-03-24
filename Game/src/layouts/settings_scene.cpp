#include "main/mainwindow.h"

void MainWindow::SetupSettingsScene(){
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

    QPushButton *apiLoadButton = new QPushButton("Load data from API");
    apiLoadButton->setFixedWidth(280);
    apiLoadButton->setFixedHeight(100);
    apiLoadButton->setStyleSheet(style);
    connect(apiLoadButton, &QPushButton::clicked, this, &MainWindow::LoadAllDataFromAPI);
    mainLay->addWidget(apiLoadButton);

    QPushButton *dbLoadButton = new QPushButton("Load data from DB");
    dbLoadButton->setFixedWidth(280);
    dbLoadButton->setFixedHeight(100);
    dbLoadButton->setStyleSheet(style);
    connect(dbLoadButton, &QPushButton::clicked, this, &MainWindow::LoadAllDataFromDB);
    mainLay->addWidget(dbLoadButton);

    QPushButton *recountButton = new QPushButton("Re-evaluate all variables");
    recountButton->setFixedHeight(100);
    recountButton->setStyleSheet(style);
    connect(recountButton, &QPushButton::clicked, this, &MainWindow::RecountEverything);
    mainLay->addWidget(recountButton);

    QPushButton *saveButton = new QPushButton("Save all data");
    saveButton->setFixedWidth(280);
    saveButton->setFixedHeight(100);
    saveButton->setStyleSheet(style);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::SaveAllDataDefault);
    mainLay->addWidget(saveButton);

    PushBackEmptyToLay(2);
}
