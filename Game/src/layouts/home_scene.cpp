#include "main/mainwindow.h"
#include "game/data/team.h"
#include "game/data/player.h"
#include "game/data/player_position.h"

void MainWindow::SetupHomeScene(){
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

    QString playerButtonStyle =
            "QPushButton{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: transparent;"
                "font-size: 20px;"
                "font-weight: bold;"
                "font-family: Comic Sans MS;"
                "color: rgb(211, 242, 254);"
            "}"
            ":hover{"
                "color: orange;"
            "}";

    ClearLay();

    const int playerLabelHeight = 40;
    CLUB* club = user->getClub();
    QList<PLAYER*> players = club->getPlayers();

    TakeSpaceInLay(50, 0, 3);

    playersScrollArea = new QScrollArea;
    playersScrollArea->setFixedSize(1200, 700);
    playersScrollArea->setStyleSheet(scrollAreaStyle);
    playersScrollArea->scrollBarWidgets(Qt::AlignHorizontal_Mask);
    playersScrollAreaWidget = new QWidget(playersScrollArea);
    playersScrollAreaWidget->setStyleSheet(scrollAreaWidgetStyle);
    playersLay = new QGridLayout(playersScrollAreaWidget);
    int curRow = 0;
    for(const auto& p : players){
        QPushButton* name = new QPushButton(p->getName());
        name->setStyleSheet(playerButtonStyle);
        name->setFixedSize(450, playerLabelHeight);

        QLabel* pos = new QLabel(p->getPos()->getStrName());
        pos->setStyleSheet(infoLabelStyle);
        pos->setFixedSize(120, playerLabelHeight);

        QLabel* age = new QLabel(QString::number(p->getAge()));
        age->setStyleSheet(infoLabelStyle);
        age->setFixedSize(70, playerLabelHeight);

        QLabel* skill = new QLabel(QString::number(p->getSkill()));
        skill->setStyleSheet(infoLabelStyle);
        skill->setFixedSize(70, playerLabelHeight);

        QLabel* TV = new QLabel(NaturalizeNum(p->getTV()) + EURO);
        TV->setStyleSheet(infoLabelStyle);
        TV->setFixedSize(200, playerLabelHeight);

        playersLay->addWidget(name, curRow, 0, Qt::AlignCenter);
        playersLay->addWidget(pos, curRow, 1, Qt::AlignCenter);
        playersLay->addWidget(age, curRow, 2, Qt::AlignCenter);
        playersLay->addWidget(TV, curRow, 3, Qt::AlignCenter);
        playersLay->addWidget(skill, curRow, 4, Qt::AlignCenter);
        ++curRow;
    }

    playersScrollArea->setWidget(playersScrollAreaWidget);
    playersScrollAreaWidget->setLayout(playersLay);

    mainLay->addWidget(playersScrollArea, 1, 1, Qt::AlignCenter);

    TakeSpaceInLay(50, 0, 3);
}
