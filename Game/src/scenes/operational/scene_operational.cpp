#include "main/mainwindow.h"

//This function should be called just once
void MainWindow::InitAllScenes()
{
    for(const int& i : allScenes){
        if(QWidget* curw_ptr = InitScene(i)){
            curw_ptr->setFixedSize(_width, _height);
            //qDebug() << _width << " " << _height;
            mainWidget->addWidget(curw_ptr);
        }
    }
}

QWidget* MainWindow::InitScene(int scene)
{
    switch (scene) {
    case STARTING_SCENE:
        startingSceneMainWidget = new QWidget();
        startingSceneMainLayout = new QGridLayout(startingSceneMainWidget);
        return startingSceneMainWidget;
    case SETTINGS_SCENE:
        settingsSceneMainWidget = new QWidget();
        settingsSceneMainLayout = new QGridLayout(settingsSceneMainWidget);
        return settingsSceneMainWidget;
    case NEW_GAME_SCENE:
        newGameSceneMainWidget = new QWidget();
        newGameSceneMainLayout = new QGridLayout(newGameSceneMainWidget);
        return newGameSceneMainWidget;
    case HOME_SCENE:
        homeSceneMainWidget = new QWidget();
        homeSceneMainLayout = new QGridLayout(homeSceneMainWidget);
        return homeSceneMainWidget;
    case TRANSFERS_SCENE:
        transfersSceneMainWidget = new QWidget();
        transfersSceneMainLayout = new QGridLayout(transfersSceneMainWidget);
        return transfersSceneMainWidget;
    default:
        qDebug() << "Unexpected scene id was provided to InitScene() function";
        return nullptr;
    }
}
