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

    QString headerLabelStyle =
            "QLabel{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: transparent;"
                "font-size: 23px;"
                "font-weight: bold;"
                "font-family: Comic Sans MS;"
                "color: rgb(211, 242, 254);"
            "}";

    QString headerButtonStyle =
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
                "color: blue;"
            "}";

    ClearLay();

    const int headerLabelHeight = 30;
    CLUB* club = user->getClub();
    homeScenePlayers = club->getPlayers();

    TakeSpaceInLay(100, 0, 3);

    playersHeaderLay = new QGridLayout();
    //playersHeaderLay->setGeometry(QRect(0, 0, 1000, headerLabelHeight));

    QLabel* nationHeader = new QLabel("Nation");
    nationHeader->setFixedSize(120, headerLabelHeight);
    nationHeader->setStyleSheet(headerLabelStyle);

    QPushButton* nameHeader = new QPushButton("Name");
    nameHeader->setStyleSheet(headerButtonStyle);
    nameHeader->setFixedSize(390, headerLabelHeight);
    connect(nameHeader, &QPushButton::clicked, this, [this]{
        HomeSceneSortPlayersByName();
        ClearLay(playersLay);
        HomeSceneAddPlayersToLay();
    });

    QPushButton* posHeader = new QPushButton("Position");
    posHeader->setStyleSheet(headerButtonStyle);
    posHeader->setFixedSize(90, headerLabelHeight);
    connect(posHeader, &QPushButton::clicked, this, [this]{
        HomeSceneSortPlayersByPos();
        ClearLay(playersLay);
        HomeSceneAddPlayersToLay();
    });

    QPushButton* ageHeader = new QPushButton(" Age");
    ageHeader->setStyleSheet(headerButtonStyle);
    ageHeader->setFixedSize(60, headerLabelHeight);
    connect(ageHeader, &QPushButton::clicked, this, [this]{
        HomeSceneSortPlayersByAge();
        ClearLay(playersLay);
        HomeSceneAddPlayersToLay();
    });

    QPushButton* skillHeader = new QPushButton("Rating");
    skillHeader->setStyleSheet(headerButtonStyle);
    skillHeader->setFixedSize(110, headerLabelHeight);
    connect(skillHeader, &QPushButton::clicked, this, [this]{
        HomeSceneSortPlayersBySkill();
        ClearLay(playersLay);
        HomeSceneAddPlayersToLay();
    });

    QPushButton* TVHeader = new QPushButton("Value");
    TVHeader->setStyleSheet(headerButtonStyle);
    TVHeader->setFixedSize(170, headerLabelHeight);
    connect(TVHeader, &QPushButton::clicked, this, [this]{
        HomeSceneSortPlayersByTV();
        ClearLay(playersLay);
        HomeSceneAddPlayersToLay();
    });

    playersHeaderLay->addWidget(nationHeader, 0, 0, Qt::AlignLeft);
    playersHeaderLay->addWidget(nameHeader, 0, 1, Qt::AlignLeft);
    playersHeaderLay->addWidget(posHeader, 0, 2, Qt::AlignLeft);
    playersHeaderLay->addWidget(ageHeader, 0, 3, Qt::AlignLeft);
    playersHeaderLay->addWidget(TVHeader, 0, 4, Qt::AlignLeft);
    playersHeaderLay->addWidget(skillHeader, 0, 5, Qt::AlignLeft);

    mainLay->addLayout(playersHeaderLay, 1, 1);

    playersScrollArea = new QScrollArea;
    playersScrollArea->setFixedSize(1000, 600);
    playersScrollArea->setStyleSheet(scrollAreaStyle);
    playersScrollArea->scrollBarWidgets(Qt::AlignHorizontal_Mask);
    playersScrollAreaWidget = new QWidget(playersScrollArea);
    playersScrollAreaWidget->setStyleSheet(scrollAreaWidgetStyle);
    playersLay = new QGridLayout(playersScrollAreaWidget);

    HomeSceneAddPlayersToLay();

    playersScrollArea->setWidget(playersScrollAreaWidget);
    playersScrollAreaWidget->setLayout(playersLay);

    mainLay->addWidget(playersScrollArea, 2, 1, Qt::AlignCenter);

    TakeSpaceInLay(150, 3, 3);
}

void MainWindow::HomeSceneAddPlayersToLay(){
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
    for(const auto& p : homeScenePlayers){
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

        playersLay->addWidget(flag, curRow, 0, Qt::AlignCenter);
        playersLay->addWidget(name, curRow, 1, Qt::AlignCenter);
        playersLay->addWidget(pos, curRow, 2, Qt::AlignCenter);
        playersLay->addWidget(age, curRow, 3, Qt::AlignCenter);
        playersLay->addWidget(TV, curRow, 4, Qt::AlignCenter);
        playersLay->addWidget(skill, curRow, 5, Qt::AlignCenter);
        ++curRow;
    }
}

void MainWindow::HomeSceneSortPlayersByName()
{
    std::sort(homeScenePlayers.begin(), homeScenePlayers.end(), PLAYER::CompTwoPlayersByName);
}

void MainWindow::HomeSceneSortPlayersByPos()
{
    std::sort(homeScenePlayers.begin(), homeScenePlayers.end(), PLAYER::CompTwoPlayersByPos);
}

void MainWindow::HomeSceneSortPlayersByAge()
{
    std::sort(homeScenePlayers.begin(), homeScenePlayers.end(), PLAYER::CompTwoPlayersByAge);
}

void MainWindow::HomeSceneSortPlayersByTV()
{
    std::sort(homeScenePlayers.begin(), homeScenePlayers.end(), PLAYER::CompTwoPlayersByTV);
}

void MainWindow::HomeSceneSortPlayersBySkill()
{
    std::sort(homeScenePlayers.begin(), homeScenePlayers.end(), PLAYER::CompTwoPlayersBySkill);
}
