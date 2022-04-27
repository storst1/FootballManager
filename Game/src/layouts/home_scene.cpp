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

    SetupNavigationLay();
    mainLay->addLayout(navigationLay, 0, 1);

    const int headerLabelHeight = 30;
    CLUB* club = user->getClub();
    homeScenePlayers = club->getPlayers();
    homeSceneLastSortClicked = Pos;

    //TakeSpaceInLay(100, 0, 3);

    homeScenePlayersHeaderLay = new QGridLayout();
    //playersHeaderLay->setGeometry(QRect(0, 0, 1000, headerLabelHeight));

    QLabel* nationHeader = new QLabel("Nation");
    nationHeader->setFixedSize(120, headerLabelHeight);
    nationHeader->setStyleSheet(headerLabelStyle);

    QPushButton* nameHeader = new QPushButton("Name");
    nameHeader->setStyleSheet(headerButtonStyle);
    nameHeader->setFixedSize(390, headerLabelHeight);
    connect(nameHeader, &QPushButton::clicked, this, [this]{
        homeSceneLastSortClicked == Name ? ReverseHomeScenePlayers() :   HomeSceneSortPlayersByName();
        ClearLay(homeScenePlayersLay);
        HomeSceneAddPlayersToLay();
        homeSceneLastSortClicked = Name;
    });

    QPushButton* posHeader = new QPushButton("Position");
    posHeader->setStyleSheet(headerButtonStyle);
    posHeader->setFixedSize(90, headerLabelHeight);
    connect(posHeader, &QPushButton::clicked, this, [this]{
        homeSceneLastSortClicked == Pos ? ReverseHomeScenePlayers() : HomeSceneSortPlayersByPos();
        ClearLay(homeScenePlayersLay);
        HomeSceneAddPlayersToLay();
        homeSceneLastSortClicked = Pos;
    });

    QPushButton* ageHeader = new QPushButton(" Age");
    ageHeader->setStyleSheet(headerButtonStyle);
    ageHeader->setFixedSize(60, headerLabelHeight);
    connect(ageHeader, &QPushButton::clicked, this, [this]{
        homeSceneLastSortClicked == Age ? ReverseHomeScenePlayers() : HomeSceneSortPlayersByAge();
        ClearLay(homeScenePlayersLay);
        HomeSceneAddPlayersToLay();
        homeSceneLastSortClicked = Age;
    });

    QPushButton* skillHeader = new QPushButton("Rating");
    skillHeader->setStyleSheet(headerButtonStyle);
    skillHeader->setFixedSize(110, headerLabelHeight);
    connect(skillHeader, &QPushButton::clicked, this, [this]{
        homeSceneLastSortClicked == Skill ? ReverseHomeScenePlayers() : HomeSceneSortPlayersBySkill();
        ClearLay(homeScenePlayersLay);
        HomeSceneAddPlayersToLay();
        homeSceneLastSortClicked = Skill;
    });

    QPushButton* TVHeader = new QPushButton("Value");
    TVHeader->setStyleSheet(headerButtonStyle);
    TVHeader->setFixedSize(170, headerLabelHeight);
    connect(TVHeader, &QPushButton::clicked, this, [this]{
        homeSceneLastSortClicked == TV ? ReverseHomeScenePlayers() : HomeSceneSortPlayersByTV();
        ClearLay(homeScenePlayersLay);
        HomeSceneAddPlayersToLay();
        homeSceneLastSortClicked = TV;
    });

    homeScenePlayersHeaderLay->addWidget(nationHeader, 0, 0, Qt::AlignLeft);
    homeScenePlayersHeaderLay->addWidget(nameHeader, 0, 1, Qt::AlignLeft);
    homeScenePlayersHeaderLay->addWidget(posHeader, 0, 2, Qt::AlignLeft);
    homeScenePlayersHeaderLay->addWidget(ageHeader, 0, 3, Qt::AlignLeft);
    homeScenePlayersHeaderLay->addWidget(TVHeader, 0, 4, Qt::AlignLeft);
    homeScenePlayersHeaderLay->addWidget(skillHeader, 0, 5, Qt::AlignLeft);

    mainLay->addLayout(homeScenePlayersHeaderLay, 1, 1);

    homeScenePlayersScrollArea = new QScrollArea;
    homeScenePlayersScrollArea->setFixedSize(1000, 600);
    homeScenePlayersScrollArea->setStyleSheet(scrollAreaStyle);
    homeScenePlayersScrollArea->scrollBarWidgets(Qt::AlignHorizontal_Mask);
    homeScenePlayersScrollAreaWidget = new QWidget(homeScenePlayersScrollArea);
    homeScenePlayersScrollAreaWidget->setStyleSheet(scrollAreaWidgetStyle);
    homeScenePlayersLay = new QGridLayout(homeScenePlayersScrollAreaWidget);

    HomeSceneAddPlayersToLay();

    homeScenePlayersScrollArea->setWidget(homeScenePlayersScrollAreaWidget);
    homeScenePlayersScrollAreaWidget->setLayout(homeScenePlayersLay);

    mainLay->addWidget(homeScenePlayersScrollArea, 2, 1, Qt::AlignCenter);

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

        homeScenePlayersLay->addWidget(flag, curRow, 0, Qt::AlignCenter);
        homeScenePlayersLay->addWidget(name, curRow, 1, Qt::AlignCenter);
        homeScenePlayersLay->addWidget(pos, curRow, 2, Qt::AlignCenter);
        homeScenePlayersLay->addWidget(age, curRow, 3, Qt::AlignCenter);
        homeScenePlayersLay->addWidget(TV, curRow, 4, Qt::AlignCenter);
        homeScenePlayersLay->addWidget(skill, curRow, 5, Qt::AlignCenter);
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

void MainWindow::ReverseHomeScenePlayers()
{
    std::reverse(homeScenePlayers.begin(), homeScenePlayers.end());
}
