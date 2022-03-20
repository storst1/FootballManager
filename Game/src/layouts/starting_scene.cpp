#include "main/mainwindow.h"

void MainWindow::SetupStartingScene(){
    QPushButton* apiButton = new QPushButton("API Button");
    apiButton->setFixedWidth(150);
    apiButton->setFixedHeight(50);
    mainLay->addWidget(apiButton);
}
