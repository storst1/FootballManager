#include "main/mainwindow.h"
#include "game/data/team.h"
#include "game/data/player.h"
#include "game/data/player_position.h"
#include "game/data/game_data.h"

void MainWindow::SetupTransfersScene()
{

    QString scrollAreaStyle =
            "QScrollArea{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: transparent;"
            "}"
            "QScrollArea > QWidget > QScrollBar:vertical {"
                "background: palette(base)"
            "}"
            "QScrollArea > QWidget > QScrollBar:handle:vertical {"
                "background: rgb(141,232,123);"
            "}"
            "QScrollArea > QWidget > QScrollBar:add-page:vertical {"
                "background: rgb(225,252,220);"
            "}"
            "QScrollArea > QWidget > QScrollBar:sub-page:vertical {"
                "background: rgb(225,252,220);"
            "}";

    QString scrollAreaWidgetStyle =
            "QScrollArea > QWidget > QWidget{"
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: transparent;"
            "}";

    ClearLay();

    SetupNavigationLay();
    mainLay->addLayout(navigationLay, 0, 1);

    transfersScenePlayers = gameData->getPlayersListConditional(100);
    transfersSceneLastSortClicked = None;

    transfersScenePlayersScrollArea = new QScrollArea;
    transfersScenePlayersScrollArea->setFixedSize(1000, 600);
    transfersScenePlayersScrollArea->setStyleSheet(scrollAreaStyle);
    transfersScenePlayersScrollArea->scrollBarWidgets(Qt::AlignHorizontal_Mask);
    transfersScenePlayersScrollAreaWidget = new QWidget(transfersScenePlayersScrollArea);
    transfersScenePlayersScrollAreaWidget->setStyleSheet(scrollAreaWidgetStyle);
    transfersScenePlayersLay = new QGridLayout(transfersScenePlayersScrollAreaWidget);

    TransfersSceneAddPlayersToLay();

    transfersScenePlayersScrollArea->setWidget(transfersScenePlayersScrollAreaWidget);
    transfersScenePlayersScrollAreaWidget->setLayout(transfersScenePlayersLay);

    mainLay->addWidget(transfersScenePlayersScrollArea, 2, 1, Qt::AlignCenter);

    TakeSpaceInLay(50, 3, 3);
}

void MainWindow::TransfersSceneAddPlayersToLay(){
    QString playerButtonStyle =
            "QPushButton{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: transparent;"
                "font-size: 23px;"
                "font-weight: bold;"
                "font-family: Comic Sans MS;"
                "color: rgb(211, 242, 254);"
                "text-align: left;"
            "}"
            ":hover{"
                "color: orange;"
            "}";

    QString infoLabelStyle =
            "QLabel{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: transparent;"
                "font-size: 18px;"
                "font-family: Comic Sans MS;"
                "color: white;"
            "}";

    const int playerLabelHeight = 40;

    int curRow = 0;
    for(const auto& p : transfersScenePlayers){
        QPixmap flagPixmap(110, 40);
        drawPlayerFlag(flagPixmap, p->getFF(), p->getSF());
        QLabel* flag = new QLabel();
        flag->setFixedSize(110, 40);
        flag->setPixmap(flagPixmap);

        QPushButton* name = new QPushButton(p->getName());
        name->setStyleSheet(playerButtonStyle);
        name->setFixedSize(400, playerLabelHeight);

        QLabel* pos = new QLabel(p->getPos()->getStrName());
        pos->setStyleSheet(infoLabelStyle);
        pos->setFixedSize(100, playerLabelHeight);

        QLabel* age = new QLabel(QString::number(p->getAge()));
        age->setStyleSheet(infoLabelStyle);
        age->setFixedSize(70, playerLabelHeight);

        QLabel* skill = new QLabel(QString::number(p->getSkill()));
        skill->setStyleSheet(infoLabelStyle);
        skill->setFixedSize(70, playerLabelHeight);

        QLabel* TV = new QLabel(NaturalizeNum(p->getTV()) + EURO);
        TV->setStyleSheet(infoLabelStyle);
        TV->setFixedSize(180, playerLabelHeight);

        transfersScenePlayersLay->addWidget(flag, curRow, 0, Qt::AlignCenter);
        transfersScenePlayersLay->addWidget(name, curRow, 1, Qt::AlignCenter);
        transfersScenePlayersLay->addWidget(pos, curRow, 2, Qt::AlignCenter);
        transfersScenePlayersLay->addWidget(age, curRow, 3, Qt::AlignCenter);
        transfersScenePlayersLay->addWidget(TV, curRow, 4, Qt::AlignCenter);
        transfersScenePlayersLay->addWidget(skill, curRow, 5, Qt::AlignCenter);
        ++curRow;
    }
}
