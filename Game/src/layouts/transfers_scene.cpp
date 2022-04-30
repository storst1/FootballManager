#include "main/mainwindow.h"
#include "game/data/team.h"
#include "game/data/player.h"
#include "game/data/player_position.h"
#include "game/data/game_data.h"

void MainWindow::SetupTransfersScene()
{
    transfersSceneLoaded = false;

    ClearLay();

    //Navigation lay
    SetupNavigationLay();
    mainLay->addLayout(navigationLay, 0, 1);

    //Filters lay
    TransfersSceneSetupFilters();
    mainLay->addLayout(transfersSceneFiltersLay, 1, 1, Qt::AlignCenter);

    //Players lay
    TransfersSceneSetupPlayers();
    mainLay->addWidget(transfersScenePlayersScrollArea, 2, 1, Qt::AlignCenter);

    TakeSpaceInLay(150, 3, 3);
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

    QString optionsButtonStyle =
            "QPushButton{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: transparent;"
                "font-size: 23px;"
                "font-weight: bold;"
                "font-family: Comic Sans MS;"
                "color: rgb(144, 246, 141);"
                "text-align: center;"
            "}"
            ":hover{"
                "color: red;"
            "}";

    const int playerLabelHeight = 40;

    ClearLay(transfersScenePlayersLay);

    int totalPlayers = transfersScenePlayers.size();

    int curRow = 0;
    if(totalPlayers == 0){
        QLabel* noPlayersLabel = new QLabel("No players found with given requirements");
        noPlayersLabel->setStyleSheet(infoLabelStyle);
        noPlayersLabel->setFixedSize(400, playerLabelHeight);
        transfersScenePlayersLay->addWidget(noPlayersLabel, 0, 0, Qt::AlignCenter);
        ++totalPlayers;
        ++curRow;
    }
    else{
        for(const auto& p : transfersScenePlayers){
            QPixmap flagPixmap(110, 40);
            drawPlayerFlag(flagPixmap, p->getFF(), p->getSF());
            QLabel* flag = new QLabel();
            flag->setFixedSize(110, 40);
            flag->setPixmap(flagPixmap);

            QPushButton* name = new QPushButton(p->getName());
            name->setStyleSheet(playerButtonStyle);
            name->setFixedSize(350, playerLabelHeight);

            QLabel* pos = new QLabel(p->getPos()->getStrName());
            pos->setStyleSheet(infoLabelStyle);
            pos->setFixedSize(100, playerLabelHeight);

            QLabel* team = new QLabel(p->getClub()->getName());
            team->setStyleSheet(infoLabelStyle);
            team->setFixedSize(200, playerLabelHeight);

            QLabel* age = new QLabel(QString::number(p->getAge()));
            age->setStyleSheet(infoLabelStyle);
            age->setFixedSize(70, playerLabelHeight);

            QLabel* skill = new QLabel(QString::number(p->getSkill()));
            skill->setStyleSheet(infoLabelStyle);
            skill->setFixedSize(70, playerLabelHeight);

            QLabel* TV = new QLabel(NaturalizeNum(p->getTV()) + EURO);
            TV->setStyleSheet(infoLabelStyle);
            TV->setFixedSize(180, playerLabelHeight);

            QPushButton* options = new QPushButton("Explore options");
            options->setFixedSize(170, playerLabelHeight);
            options->setStyleSheet(optionsButtonStyle);

            transfersScenePlayersLay->addWidget(flag, curRow, 0, Qt::AlignCenter);
            transfersScenePlayersLay->addWidget(name, curRow, 1, Qt::AlignCenter);
            transfersScenePlayersLay->addWidget(pos, curRow, 2, Qt::AlignCenter);
            transfersScenePlayersLay->addWidget(team, curRow, 3, Qt::AlignCenter);
            transfersScenePlayersLay->addWidget(age, curRow, 4, Qt::AlignCenter);
            transfersScenePlayersLay->addWidget(TV, curRow, 5, Qt::AlignCenter);
            transfersScenePlayersLay->addWidget(skill, curRow, 6, Qt::AlignCenter);
            transfersScenePlayersLay->addWidget(options, curRow, 7, Qt::AlignCenter);
            ++curRow;
        }
    }
    while(totalPlayers < 50){
        QLabel* blankLabel = new QLabel("");
        blankLabel->setStyleSheet(infoLabelStyle);
        blankLabel->setFixedSize(1, playerLabelHeight);
        transfersScenePlayersLay->addWidget(blankLabel, curRow, 0, Qt::AlignCenter);
        ++curRow;
        ++totalPlayers;
    }
}

void MainWindow::TransfersSceneClearNameFilter()
{
    while(transfersSceneCountryFilter->count()){
        transfersSceneCountryFilter->removeItem(0);
    }
}

QList<FEDERATION *> MainWindow::TransfersSceneGetCurContents()
{
    QList<FEDERATION *> curContents;
    QString strFilter = transfersSceneCountryFilter->currentText();
    if(strFilter.length() < 3){
        for(int i = 0; i < transfersSceneFederationsList.size(); ++i){
            curContents.push_back(transfersSceneFederationsList[i]);
        }
    }
    else{
        for(int i = 0; i < transfersSceneFederationsList.size(); ++i){
            if(transfersSceneFederationsList[i]->getName().contains(strFilter)){
                curContents.push_back(transfersSceneFederationsList[i]);
            }
        }
    }
    return curContents;
}

void MainWindow::TransfersSceneFillCountryFilter(QList<FEDERATION *> &list)
{
    for(const auto &l : list){
        transfersSceneCountryFilter->insertItem
        (
            transfersSceneCountryFilter->count(),
            QIcon(*l->getFlag()),
            l->getName(),
            l->getId()
        );
    }
}

void MainWindow::TransfersSceneSetupFilters()
{

    QString buttonStyle = "QPushButton{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: none;"
                "background-image:url(:/greenLay160x60.png);"
                "font-size: 24px;"
                "font-family: Comic Sans MS;"
                "color: white;"
            "}"
            ":hover{"
                "background-image:url(:/greenLay160x60Highlighted.png);"
            "}";

    QString comboBoxStyle = "QComboBox QAbstractItemView {"
            "border: 2px solid darkgray;"
            "selection-background-color: green;"
        "}";

    transfersSceneFiltersLay = new QGridLayout;

    transfersSceneFederationsList = gameData->getFederationsList();
    std::sort(transfersSceneFederationsList.begin(), transfersSceneFederationsList.end(), FEDERATION::CompTwoFedsByName);

    transfersSceneCountryCompleter = new QCompleter();
    transfersSceneCountryCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    transfersSceneCountryCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);

    transfersSceneCountryFilter = new QComboBox();
    //transfersSceneNameFilter->setEditable(true);
    transfersSceneCountryFilter->setEditable(false);
    transfersSceneCountryFilter->setFixedSize(200, 35);
    transfersSceneCountryFilter->setStyleSheet(comboBoxStyle);
    //transfersSceneNameFilter->setCompleter(transfersSceneNameCompleter);
    transfersSceneCountryFilterCurrentContents = TransfersSceneGetCurContents();
    transfersSceneCountryFilter->insertItem(0, "Select country", -1);
    TransfersSceneFillCountryFilter(transfersSceneCountryFilterCurrentContents);
    //transfersSceneNameFilter->setCurrentText("");
    /*
    connect(transfersSceneNameFilter, &QComboBox::editTextChanged, this, [this]{
        if(transfersSceneNameFilter->currentText() == transferstScenePreInsertText){
            qDebug() << "Same input";
            return;
        }
        if(transferstSceneInsertSignal){
            qDebug() << "Cutting signal";
            transferstSceneInsertSignal = false;
            transfersSceneNameFilter->setCurrentText(transferstScenePreInsertText);
            return;
        }
        qDebug() << "Filtering contents";
        transferstScenePreInsertText = transfersSceneNameFilter->currentText();
        transfersSceneNameFilterCurrentContents = TransfersSceneGetCurContents();
        transferstSceneInsertSignal = true;
        transfersSceneNameFilter->clear();
        transferstSceneInsertSignal = true;
        transfersSceneNameFilter->insertItems(0, transfersSceneNameFilterCurrentContents);
        //transfersSceneNameFilter->setCurrentText("");
    });
    */
    transfersSceneFiltersLay->addWidget(transfersSceneCountryFilter, 0, 0);

    transfersScenePosFilter = new QComboBox();
    transfersScenePosFilter->setEditable(false);
    transfersScenePosFilter->setFixedSize(60, 35);
    transfersScenePosFilter->setStyleSheet(comboBoxStyle);
    transfersScenePosFilter->insertItem(0, "Any", -1);
    TransfersSceneFillPosFilter();
    transfersSceneFiltersLay->addWidget(transfersScenePosFilter, 0, 1);

    transfersSceneSearchButton = new QPushButton("Search");
    transfersSceneSearchButton->setStyleSheet(buttonStyle);
    transfersSceneSearchButton->setFixedSize(160, 60);
    connect(transfersSceneSearchButton, &QPushButton::clicked, this, [this]{
        TransfersSceneUpdatePlayersList();
    });

    transfersSceneFiltersLay->addWidget(transfersSceneSearchButton, 0, 2);
}

void MainWindow::TransfersSceneSetupPlayers()
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

    transfersScenePlayers = gameData->getPlayersListConditional(50);
    transfersSceneLastSortClicked = None;

    transfersScenePlayersScrollArea = new QScrollArea;
    transfersScenePlayersScrollArea->setFixedSize(1400, 450);
    transfersScenePlayersScrollArea->setStyleSheet(scrollAreaStyle);
    transfersScenePlayersScrollArea->scrollBarWidgets(Qt::AlignHorizontal_Mask);
    transfersScenePlayersScrollAreaWidget = new QWidget(transfersScenePlayersScrollArea);
    transfersScenePlayersScrollAreaWidget->setStyleSheet(scrollAreaWidgetStyle);
    transfersScenePlayersLay = new QGridLayout(transfersScenePlayersScrollAreaWidget);

    TransfersSceneAddPlayersToLay();

    transfersScenePlayersScrollArea->setWidget(transfersScenePlayersScrollAreaWidget);
    transfersScenePlayersScrollAreaWidget->setLayout(transfersScenePlayersLay);

}

void MainWindow::TransfersSceneUpdatePlayersList()
{
    transfersScenePlayers = gameData->getPlayersListConditionalByFilter(50, TransfersSceneGetCurrentFilter());
    TransfersSceneAddPlayersToLay();
    transfersScenePlayersScrollArea->verticalScrollBar()->setValue(0);
}

PLAYER_SEARCH_FILTER MainWindow::TransfersSceneGetCurrentFilter() const
{
    PLAYER_SEARCH_FILTER filter;
    int fedId = transfersSceneCountryFilter->currentData().value<int>();
    if(fedId != -1){
        filter.setNations({gameData->getFederationById(fedId)});
    }
    int curPos = transfersScenePosFilter->currentData().value<int>();
    if(curPos != -1){
        filter.setPos({curPos});
    }
    return filter;
}

void MainWindow::TransfersSceneFillPosFilter() const
{
    QList<QPair<QString, int>> posList = GAME_DATA::getPositionsSimplifiedList();
    for(const auto &p : posList){
        transfersScenePosFilter->addItem(p.first, p.second);
    }
}
