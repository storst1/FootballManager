#include "main/mainwindow.h"
#include "game/data/team.h"
#include "game/data/player.h"
#include "game/data/player_position.h"
#include "game/data/game_data.h"

void MainWindow::SetupTransfersScene()
{
    transfersSceneLoaded = false;

    sceneSwitch->Switch(TRANSFERS_SCENE);
    ClearLay(transfersSceneMainLayout);

    //Navigation lay
    SetupNavigationLay();
    transfersSceneMainLayout->addLayout(navigationLay, 0, 1);

    //Filters lay
    TransfersSceneSetupFilters();
    transfersSceneMainLayout->addLayout(transfersSceneFiltersLay, 1, 1, Qt::AlignCenter);

    //Players lay
    TransfersSceneSetupPlayers();
    transfersSceneMainLayout->addWidget(transfersScenePlayersScrollArea, 2, 1, Qt::AlignCenter);

    TakeSpaceInLay(transfersSceneMainLayout, 150, 3, 3);
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
QVector<FEDERATION *> MainWindow::TransfersSceneGetCurContents()
{
    QVector<FEDERATION *> curContents;
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

void MainWindow::TransfersSceneFillCountryFilter(QVector<FEDERATION *> &list)
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

void MainWindow::TransfersSceneFillSecondCountryFilter(QVector<FEDERATION *> &list)
{
    for(const auto &l : list){
        transfersSceneSecondCountryFilter->insertItem
        (
            transfersSceneSecondCountryFilter->count(),
            QIcon(*(l->getFlag())),
            l->getName(),
            l->getId()
        );
    }
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
    QString name = transfersSceneNameFilter->text();
    if(name != ""){
        filter.setName(name);
    }
    int fedId = transfersSceneCountryFilter->currentData().value<int>();
    if(fedId != -1){
        filter.setNations({gameData->getFederationById(fedId)});
    }
    int secondFedId = transfersSceneSecondCountryFilter->currentData().value<int>();
    if(secondFedId != -1){
        filter.setSecondNations({gameData->getFederationById(secondFedId)});
    }
    int pos = transfersScenePosFilter->currentData().value<int>();
    if(pos != -1){
        filter.setPos({pos});
    }
    int secondPos = transfersSceneSecondPosFilter->currentData().value<int>();
    if(secondPos != -1){
        filter.setSecondPos({secondPos});
    }
    QString minAge = transfersSceneMinAgeFilter->text();
    if(minAge != ""){
        filter.setMinAge(minAge.toInt());
    }
    QString maxAge = transfersSceneMaxAgeFilter->text();
    if(maxAge != ""){
        filter.setMaxAge(maxAge.toInt());
    }
    QString minSkill = transfersSceneMinSkillFilter->text();
    if(minSkill != ""){
        filter.setMinSkill(minSkill.toInt());
    }
    QString maxSkill = transfersSceneMaxSkillFilter->text();
    if(maxSkill != ""){
        filter.setMaxSkill(maxSkill.toInt());
    }
    return filter;
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

    transfersSceneFiltersLay = new QGridLayout;

    transfersSceneFederationsList = gameData->getFederationsList();
    std::sort(transfersSceneFederationsList.begin(), transfersSceneFederationsList.end(), FEDERATION::CompTwoFedsByName);

    TransfersSceneSetupNameFilter();
    transfersSceneFiltersLay->addWidget(transfersSceneNameFilter, 0, 0, Qt::AlignCenter);

    TransfersSceneSetupCountryFilter();
    transfersSceneFiltersLay->addWidget(transfersSceneCountryFilter, 0, 1, Qt::AlignCenter);

    TransfersSceneSetupSecondCountryFilter();
    transfersSceneFiltersLay->addWidget(transfersSceneSecondCountryFilter, 0, 2, Qt::AlignCenter);

    TransfersSceneSetupPosFilter();
    transfersSceneFiltersLay->addWidget(transfersScenePosFilter, 0, 3, Qt::AlignCenter);

    TransfersSceneSetupSecondPosFilter();
    transfersSceneFiltersLay->addWidget(transfersSceneSecondPosFilter, 0, 4, Qt::AlignCenter);

    transfersSceneSearchButton = new QPushButton("Search");
    transfersSceneSearchButton->setStyleSheet(buttonStyle);
    transfersSceneSearchButton->setFixedSize(160, 60);
    connect(transfersSceneSearchButton, &QPushButton::clicked, this, [this]{
        TransfersSceneUpdatePlayersList();
    });

    transfersSceneFiltersLay->addWidget(transfersSceneSearchButton, 0, 5, Qt::AlignCenter);

    TransfersSceneSetupAgeFilter();

    transfersSceneFiltersLay->addWidget(transfersSceneMinAgeFilter, 1, 0, Qt::AlignCenter);
    transfersSceneFiltersLay->addWidget(transfersSceneMaxAgeFilter, 1, 1, Qt::AlignCenter);

    TransfersSceneSetupSkillFilter();

    transfersSceneFiltersLay->addWidget(transfersSceneMinSkillFilter, 1, 2, Qt::AlignCenter);
    transfersSceneFiltersLay->addWidget(transfersSceneMaxSkillFilter, 1, 3, Qt::AlignCenter);

    transfersSceneFiltersLay->addWidget(NewTrashPtr(), 1, 4, Qt::AlignCenter);
    transfersSceneFiltersLay->addWidget(NewTrashPtr(), 1, 5, Qt::AlignCenter);
}

void MainWindow::TransfersSceneFillPosFilter()
{
    QVector<QPair<QString, int>> posList = GAME_DATA::getPositionsSimplifiedList();
    for(const auto &p : posList){
        transfersScenePosFilter->addItem(p.first, p.second);
    }
}

void MainWindow::TransfersSceneFillSecondPosFilter()
{
    QVector<QPair<QString, int>> posList = GAME_DATA::getPositionsSimplifiedList();
    for(const auto &p : posList){
        transfersSceneSecondPosFilter->addItem(p.first, p.second);
    }
}

void MainWindow::TransfersSceneFillBothPosFilters()
{
    TransfersSceneFillPosFilter();
    TransfersSceneFillSecondPosFilter();
}

void MainWindow::TransfersSceneSetupNameFilter()
{
    transfersSceneNameFilter = new QLineEdit();
    transfersSceneNameFilter->setFixedSize(140, 35);
    transfersSceneNameFilter->setPlaceholderText("Name");
    transfersSceneNameFilter->setClearButtonEnabled(true);
}

void MainWindow::TransfersSceneSetupCountryFilter()
{

    QString comboBoxStyle = "QComboBox QAbstractItemView {"
            "border: 2px solid darkgray;"
            "selection-background-color: green;"
        "}";

    /*
    transfersSceneCountryCompleter = new QCompleter();
    transfersSceneCountryCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    transfersSceneCountryCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    */

    transfersSceneCountryFilter = new QComboBox();
    transfersSceneCountryFilter->setEditable(false);
    transfersSceneCountryFilter->setFixedSize(200, 35);
    transfersSceneCountryFilter->setStyleSheet(comboBoxStyle);
    //transfersSceneNameFilter->setCompleter(transfersSceneNameCompleter);
    //transfersSceneCountryFilterCurrentContents = TransfersSceneGetCurContents();
    transfersSceneCountryFilter->insertItem(0, "Select nationality", -1);
    TransfersSceneFillCountryFilter(transfersSceneFederationsList);
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
}

void MainWindow::TransfersSceneSetupSecondCountryFilter()
{
    QString comboBoxStyle = "QComboBox QAbstractItemView {"
            "border: 2px solid darkgray;"
            "selection-background-color: green;"
        "}";

    transfersSceneSecondCountryFilter = new QComboBox();
    transfersSceneSecondCountryFilter->setEditable(false);
    transfersSceneSecondCountryFilter->setFixedSize(200, 35);
    transfersSceneSecondCountryFilter->setStyleSheet(comboBoxStyle);
    transfersSceneSecondCountryFilter->insertItem(0, "Select second nationality", -1);
    TransfersSceneFillSecondCountryFilter(transfersSceneFederationsList);
}

void MainWindow::TransfersSceneSetupPosFilter()
{

    QString comboBoxStyle = "QComboBox QAbstractItemView {"
            "border: 2px solid darkgray;"
            "selection-background-color: green;"
        "}";

    transfersScenePosFilter = new QComboBox();
    transfersScenePosFilter->setEditable(false);
    transfersScenePosFilter->setFixedSize(100, 35);
    transfersScenePosFilter->setStyleSheet(comboBoxStyle);
    transfersScenePosFilter->insertItem(0, "Any main pos", -1);
    TransfersSceneFillPosFilter();
}

void MainWindow::TransfersSceneSetupSecondPosFilter()
{

    QString comboBoxStyle = "QComboBox QAbstractItemView {"
            "border: 2px solid darkgray;"
            "selection-background-color: green;"
        "}";

    transfersSceneSecondPosFilter = new QComboBox();
    transfersSceneSecondPosFilter->setEditable(false);
    transfersSceneSecondPosFilter->setFixedSize(100, 35);
    transfersSceneSecondPosFilter->setStyleSheet(comboBoxStyle);
    transfersSceneSecondPosFilter->insertItem(0, "Any side pos", -1);
    TransfersSceneFillSecondPosFilter();
}

void MainWindow::TransfersSceneSetupAgeFilter()
{
    QValidator* lineEditValidator = new QIntValidator(0, 100);

    transfersSceneMinAgeFilter = new QLineEdit();
    transfersSceneMinAgeFilter->setPlaceholderText("Min. age");
    transfersSceneMinAgeFilter->setFixedSize(100, 35);
    transfersSceneMinAgeFilter->setValidator(lineEditValidator);
    transfersSceneMinAgeFilter->setClearButtonEnabled(true);

    transfersSceneMaxAgeFilter = new QLineEdit();
    transfersSceneMaxAgeFilter->setPlaceholderText("Max. age");
    transfersSceneMaxAgeFilter->setFixedSize(100, 35);
    transfersSceneMaxAgeFilter->setValidator(lineEditValidator);
    transfersSceneMaxAgeFilter->setClearButtonEnabled(true);
}

void MainWindow::TransfersSceneSetupSkillFilter()
{
    QValidator* lineEditValidator = new QIntValidator(0, 100);

    transfersSceneMinSkillFilter = new QLineEdit();
    transfersSceneMinSkillFilter->setPlaceholderText("Min. skill");
    transfersSceneMinSkillFilter->setFixedSize(100, 35);
    transfersSceneMinSkillFilter->setValidator(lineEditValidator);
    transfersSceneMinSkillFilter->setClearButtonEnabled(true);

    transfersSceneMaxSkillFilter = new QLineEdit();
    transfersSceneMaxSkillFilter->setPlaceholderText("Max. skill");
    transfersSceneMaxSkillFilter->setFixedSize(100, 35);
    transfersSceneMaxSkillFilter->setValidator(lineEditValidator);
    transfersSceneMaxSkillFilter->setClearButtonEnabled(true);
}
