#include "main/mainwindow.h"
#include "game/data/team.h"
#include "game/data/player.h"
#include "game/data/player_position.h"

void MainWindow::SetupHomeScene(){
    ClearLay();

    CLUB* club = user->getClub();
    QList<PLAYER*> players = club->getPlayers();

    TakeSpaceInLay(50, 0, 3);

    QScrollArea* playersScrollArea = new QScrollArea;
    playersLay = new QGridLayout();
    int curRow = 0;
    for(const auto& p : players){
        QPushButton* name = new QPushButton(p->getName());
        QLabel* pos = new QLabel(p->getPos()->getStrName());
        QLabel* age = new QLabel(QString::number(p->getAge()));
        QLabel* skill = new QLabel(QString::number(p->getSkill()));
        playersLay->addWidget(name, curRow, 0, Qt::AlignCenter);
        playersLay->addWidget(pos, curRow, 1, Qt::AlignCenter);
        playersLay->addWidget(age, curRow, 2, Qt::AlignCenter);
        playersLay->addWidget(skill, curRow, 3, Qt::AlignCenter);
        ++curRow;
    }


    mainLay->addWidget(playersScrollArea, 1, 1, Qt::AlignCenter);

    TakeSpaceInLay(50, 0, 3);
}
