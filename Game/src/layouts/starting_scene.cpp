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

    QPushButton *startButton = new QPushButton("New Game");
    startButton->setFixedWidth(280);
    startButton->setFixedHeight(100);
    startButton->setStyleSheet(style);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::SetupNewGameScene);
    mainLay->addWidget(startButton);

    QPushButton* loadButton = new QPushButton("Load Game");
    loadButton->setFixedWidth(280);
    loadButton->setFixedHeight(100);
    loadButton->setStyleSheet(style);
    mainLay->addWidget(loadButton);

    PushBackEmptyToLay(2);
}
