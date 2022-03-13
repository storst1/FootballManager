#include "mainwindow.h"

void MainWindow::CollectData()
{
    QList<QPair<QString, int>> allLeagues = realDataDb->getAllLeagues();
    for(int i = 0; i < allLeagues.size(); ++i){

    }
}
