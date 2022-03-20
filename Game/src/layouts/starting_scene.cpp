#include "main/mainwindow.h"

void MainWindow::SetupStartingScene(){
    PushBackEmptyToLay(2);
    QString style =
            "QPushButton{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "background-image:url(:/button8.png);"
            "}"
            ":hover{"
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "background-image:url(:/button9.png);"
            "}";

    QPushButton *startButton = new QPushButton("New Game");
    startButton->setFixedWidth(280);
    startButton->setFixedHeight(100);
    startButton->setStyleSheet(style);
    mainLay->addWidget(startButton);

    QPushButton* loadButton = new QPushButton("Load Game");
    loadButton->setFixedWidth(280);
    loadButton->setFixedHeight(100);
    loadButton->setStyleSheet(style);
    mainLay->addWidget(loadButton);

    PushBackEmptyToLay(2);
}
