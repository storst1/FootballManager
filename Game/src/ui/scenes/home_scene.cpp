#include "main/mainwindow.h"
#include "game/data/team.h"
#include "game/data/player.h"
#include "game/data/player_position.h"
#include "ui_mainwindow.h"

void MainWindow::SetupHomeScene(){

    ui->stackedWidget->setCurrentIndex(SW_HOME_SCENE);

    //Setup layout of squad scroll area (SSA)
    HomeSceneSetupSSALay();

    //Load players data & assign other vars
    CLUB* club = user->getClub();
    homeScenePlayers = club->getPlayers();
    homeSceneLastSortClicked = Pos;

    //Add players to layout
    HomeSceneAddPlayersToLay();

    //Perform resolution adjustments
    MoveMultipleWidgetsToFitRes({
        ui->HomeSceneNLCompetitions,
        ui->HomeSceneNLHome,
        ui->HomeSceneNLTransfers,
        ui->HomeSceneSSAAge,
        ui->HomeSceneSSAName,
        ui->HomeSceneSSANation,
        ui->HomeSceneSSAPos,
        ui->HomeSceneSSARating,
        ui->HomeSceneSSAValue,
        ui->HomeSceneSSA
    });

    ResizeMultipleWidgetsToFitRes({
        ui->HomeSceneNLCompetitions,
        ui->HomeSceneNLHome,
        ui->HomeSceneNLTransfers,
        ui->HomeSceneSSAAge,
        ui->HomeSceneSSAName,
        ui->HomeSceneSSANation,
        ui->HomeSceneSSAPos,
        ui->HomeSceneSSARating,
        ui->HomeSceneSSAValue,
        ui->HomeSceneSSA
    });

    for(QWidget* wid : HomeSceneDynamicWidgetsList){
        ResizeWidgetToFitRes(wid);
    }

    /*
    sceneSwitch->Switch(HOME_SCENE);
    ClearLay(homeSceneMainLayout);

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

             QScrollArea{
                 background-color: transparent;
                 border: none;
                 background-repeat: none;
                 background: transparent;
             }
             QScrollArea > QWidget > QScrollBar:vertical {
                 background: palette(base)
             }
             QScrollArea > QWidget > QScrollBar:handle:vertical {
                 background: rgb(141,232,123);
             }
             QScrollArea > QWidget > QScrollBar:add-page:vertical {
                 background: rgb(225,252,220);
             }
             QScrollArea > QWidget > QScrollBar:sub-page:vertical {
                 background: rgb(225,252,220);
             }

    QString scrollAreaWidgetStyle =
            "QScrollArea > QWidget > QWidget{"
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: transparent;"
            "}";

              QScrollArea > QWidget > QWidget{
                  background-color: transparent;
                  border: none;
                  background-repeat: none;
                  background: transparent;
              }  ;

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

        //Pure QSS
         QPushButton{
             background-color: transparent;
             border: none;
             background-repeat: none;
             background: transparent;
             font-size: 23px;
             font-weight: bold;
             font-family: Comic Sans MS;
             color: rgb(211, 242, 254);
             text-align: left;
         }
         :hover{
             color: blue;
         } ;

    //TakeSpaceInLay(homeSceneMainLayout, 1, 0, 3);

    SetupNavigationLay();
    homeSceneMainLayout->addLayout(navigationLay, 0, 1);

    const int headerLabelHeight = 30;
    CLUB* club = user->getClub();
    homeScenePlayers = club->getPlayers();
    homeSceneLastSortClicked = Pos;

    homeScenePlayersHeaderLay = new QGridLayout();

    QLabel* nationHeader = new QLabel("Nation");
    nationHeader->setFixedSize(120, headerLabelHeight);
    nationHeader->setStyleSheet(headerLabelStyle);

    QPushButton* nameHeader = new QPushButton("Name");
    nameHeader->setStyleSheet(headerButtonStyle);
    nameHeader->setFixedSize(390, headerLabelHeight);
    connect(nameHeader, &QPushButton::clicked, this, [this]{
        homeSceneLastSortClicked == Name ? HomeSceneReversePlayers() :   HomeSceneSortPlayersByName();
        ClearLay(homeScenePlayersLay);
        HomeSceneAddPlayersToLay();
        homeSceneLastSortClicked = Name;
    });

    QPushButton* posHeader = new QPushButton("Position");
    posHeader->setStyleSheet(headerButtonStyle);
    posHeader->setFixedSize(90, headerLabelHeight);
    connect(posHeader, &QPushButton::clicked, this, [this]{
        homeSceneLastSortClicked == Pos ? HomeSceneReversePlayers() : HomeSceneSortPlayersByPos();
        ClearLay(homeScenePlayersLay);
        HomeSceneAddPlayersToLay();
        homeSceneLastSortClicked = Pos;
    });

    QPushButton* ageHeader = new QPushButton(" Age");
    ageHeader->setStyleSheet(headerButtonStyle);
    ageHeader->setFixedSize(60, headerLabelHeight);
    connect(ageHeader, &QPushButton::clicked, this, [this]{
        homeSceneLastSortClicked == Age ? HomeSceneReversePlayers() : HomeSceneSortPlayersByAge();
        ClearLay(homeScenePlayersLay);
        HomeSceneAddPlayersToLay();
        homeSceneLastSortClicked = Age;
    });

    QPushButton* skillHeader = new QPushButton("Rating");
    skillHeader->setStyleSheet(headerButtonStyle);
    skillHeader->setFixedSize(110, headerLabelHeight);
    connect(skillHeader, &QPushButton::clicked, this, [this]{
        homeSceneLastSortClicked == Skill ? HomeSceneReversePlayers() : HomeSceneSortPlayersBySkill();
        ClearLay(homeScenePlayersLay);
        HomeSceneAddPlayersToLay();
        homeSceneLastSortClicked = Skill;
    });

    QPushButton* TVHeader = new QPushButton("Value");
    TVHeader->setStyleSheet(headerButtonStyle);
    TVHeader->setFixedSize(170, headerLabelHeight);
    connect(TVHeader, &QPushButton::clicked, this, [this]{
        homeSceneLastSortClicked == TV ? HomeSceneReversePlayers() : HomeSceneSortPlayersByTV();
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

    homeSceneMainLayout->addLayout(homeScenePlayersHeaderLay, 1, 1);

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

    homeSceneMainLayout->addWidget(homeScenePlayersScrollArea, 2, 1, Qt::AlignCenter);

    HomeSceneSetupCalendarBar(eventHandler->getCurDate());

    homeSceneMainLayout->addWidget(homeSceneContinueButton, 1, 2, Qt::AlignLeft);
    homeSceneMainLayout->addWidget(homeSceneCalendarBar, 2, 2, Qt::AlignLeft);

    homeSceneSquadButton = new QPushButton("Starting 11");
    homeSceneSquadButton->setFixedSize(200, 70);
    connect(homeSceneSquadButton, &QPushButton::clicked, this, [this]{
        SetupSquadScene();
    });

    homeSceneMainLayout->addWidget(homeSceneSquadButton, 1, 0, Qt::AlignRight);

    TakeSpaceInLay(homeSceneMainLayout, 150, 3, 3);
    */
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

        HomeSceneSSALay_UI->addWidget(flag, curRow, 0, Qt::AlignCenter);
        HomeSceneSSALay_UI->addWidget(name, curRow, 1, Qt::AlignCenter);
        HomeSceneSSALay_UI->addWidget(pos, curRow, 2, Qt::AlignCenter);
        HomeSceneSSALay_UI->addWidget(age, curRow, 3, Qt::AlignCenter);
        HomeSceneSSALay_UI->addWidget(TV, curRow, 4, Qt::AlignCenter);
        HomeSceneSSALay_UI->addWidget(skill, curRow, 5, Qt::AlignCenter);

        HomeSceneDynamicWidgetsList.append({
            flag,
            name,
            pos,
            age,
            TV,
            skill
        });

        ++curRow;
    }
}

void MainWindow::HomeSceneSetupCalendarBar(DATE curDate)
{
    homeSceneCalendarBar = new QLabel();
    homeSceneCalendarBar->setFixedSize(200, 600);
    HomeSceneUpdateCalendarBar(curDate);

    homeSceneContinueButton = new QPushButton("Continue");
    homeSceneContinueButton->setFixedSize(200, 70);
    connect(homeSceneContinueButton, &QPushButton::clicked, this, [this]{
        eventHandler->NextDay();
        HomeSceneUpdateCalendarBar(eventHandler->getCurDate());
    });
}

void MainWindow::HomeSceneUpdateCalendarBar(DATE curDate)
{
    QPixmap calendarPixmap(200, 600);
    calendarPixmap.fill(Qt::transparent);
    QPainter painter(&calendarPixmap);
    for(int i = 0; i < 6; ++i){
        DATE DateToDraw = curDate.addDaysFM(i);
        HomeSceneDrawDayOnCalendarBar(DateToDraw, i, painter);
    }
    painter.end();
    homeSceneCalendarBar->setPixmap(calendarPixmap);
}

void MainWindow::HomeSceneDrawDayOnCalendarBar(DATE date, int row, QPainter& painter)
{
    row ? painter.fillRect(0, row * 100, 200, 98, Qt::blue) : painter.fillRect(0, row * 100, 200, 98, Qt::yellow);
    QPen pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);
    QFont font("Comic Sans MS", 10, 550);
    painter.setFont(font);
    painter.drawText(10, row * 100 + 30, date.MonthName() + " " + QString::number(date.Day()));

    EVENT_ARRAY dayEvents = eventHandler->getAllEventsByDateAndTeam(date, user->getClub());
    EVENT* bestDayEvent = dayEvents.getMostImportantEvent();
    if(bestDayEvent){
        bestDayEvent->paintEvent(painter, row, user->getClub());
    }
}

void MainWindow::HomeSceneSetupSSALay()
{
    ClearLay(HomeSceneSSALay_UI);
    delete HomeSceneSSALay_UI;
    HomeSceneSSALay_UI = new QGridLayout(ui->HomeSceneSSAWidget);
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

void MainWindow::HomeSceneReversePlayers()
{
    std::reverse(homeScenePlayers.begin(), homeScenePlayers.end());
}
