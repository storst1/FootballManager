#include "main/mainwindow.h"

void MainWindow::SetupTransfersScene()
{
    ClearLay();

    SetupNavigationLay();
    mainLay->addLayout(navigationLay, 0, 1);
}
