/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *StartingScene;
    QPushButton *StartingSceneNewGame;
    QPushButton *StartingSceneLoadGame;
    QPushButton *StartingSceneSettingsButton;
    QWidget *NewGameScene;
    QComboBox *NewGameSceneLeaguesComboBox;
    QLabel *NewGameSceneClubName;
    QLabel *NewGameSceneClubLogo;
    QLabel *NewGameSceneClubInfoLabel;
    QPushButton *NewGameSceneStartButton;
    QPushButton *NewGameScenePrevClubButton;
    QPushButton *NewGameSceneNextClubButton;
    QWidget *HomeScene;
    QPushButton *HomeSceneNLTransfers;
    QPushButton *HomeSceneNLHome;
    QPushButton *HomeSceneNLCompetitions;
    QPushButton *HomeSceneSSANation;
    QPushButton *HomeSceneSSAPos;
    QPushButton *HomeSceneSSAAge;
    QPushButton *HomeSceneSSAValue;
    QPushButton *HomeSceneSSARating;
    QScrollArea *HomeSceneSSA;
    QWidget *HomeSceneSSAWidget;
    QPushButton *HomeSceneSSAName;
    QLabel *HomeSceneCalendarLabel;
    QWidget *TransfersScene;
    QPushButton *TransfersSceneNLTransfers;
    QPushButton *TransfersSceneNLHome;
    QPushButton *TransfersSceneNLCompetitions;
    QPushButton *TransfersSceneSSANation;
    QPushButton *TransfersSceneSSAName;
    QPushButton *TransfersSceneSSAPos;
    QPushButton *TransfersSceneSSAAge;
    QPushButton *TransfersSceneSSAValue;
    QPushButton *TransfersSceneSSARating;
    QPushButton *TransfersSceneSSATeam;
    QScrollArea *TransfersSceneSSA;
    QWidget *TransfersSceneSSAWidget;
    QPushButton *TransfersSceneSearch;
    QComboBox *TransfersSceneFilterFN;
    QComboBox *TransfersSceneFilterSN;
    QComboBox *TransfersSceneFilterLeague;
    QLabel *TransfersSceneFNLabel;
    QLabel *TransfersSceneSNLabel;
    QLabel *TransfersSceneLeagueLabel;
    QComboBox *TransfersSceneFilterTeam;
    QLabel *TransfersSceneTeamLabel;
    QComboBox *TransfersSceneFilterMainPos;
    QLabel *TransfersSceneMainPosLabel;
    QComboBox *TransfersSceneFilterSecondPos;
    QLabel *TransfersSceneSecondPosLabel;
    QLineEdit *TransfersSceneFilterMinAge;
    QLabel *TransfersSceneMinAgeLabel;
    QLineEdit *TransfersSceneFilterMaxAge;
    QLabel *TransfersSceneMaxAgeLabel;
    QLineEdit *TransfersSceneFilterMinSkill;
    QLabel *TransfersSceneMinSkillLabel;
    QLineEdit *TransfersSceneFilterMaxSkill;
    QLabel *TransfersSceneMaxSkillLabel;
    QLineEdit *TransfersSceneFilterSearchName;
    QLabel *TransfersSceneSearchNameLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1980, 1024);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setEnabled(true);
        StartingScene = new QWidget();
        StartingScene->setObjectName(QString::fromUtf8("StartingScene"));
        StartingSceneNewGame = new QPushButton(StartingScene);
        StartingSceneNewGame->setObjectName(QString::fromUtf8("StartingSceneNewGame"));
        StartingSceneNewGame->setGeometry(QRect(820, 342, 280, 100));
        StartingSceneNewGame->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"        background-color: transparent;\n"
"        border: none;\n"
"        background-repeat: none;\n"
"        background: none;\n"
"        background-image: url(:/greenLay280x100.png);\n"
"        font-size: 22px;\n"
"        font-family: Comic Sans MS;\n"
"        color: white;\n"
"    }\n"
"   	QPushButton:hover{\n"
"        background-image:url(:/greenLay280x100Highlighted.png);\n"
"    };"));
        StartingSceneLoadGame = new QPushButton(StartingScene);
        StartingSceneLoadGame->setObjectName(QString::fromUtf8("StartingSceneLoadGame"));
        StartingSceneLoadGame->setGeometry(QRect(820, 462, 280, 100));
        StartingSceneLoadGame->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"        background-color: transparent;\n"
"        border: none;\n"
"        background-repeat: none;\n"
"        background: none;\n"
"        background-image:url(:/greenLay280x100.png);\n"
"        font-size: 22px;\n"
"        font-family: Comic Sans MS;\n"
"        color: white;\n"
"    }\n"
"    :hover{\n"
"        background-image:url(:/greenLay280x100Highlighted.png);\n"
"    };"));
        StartingSceneSettingsButton = new QPushButton(StartingScene);
        StartingSceneSettingsButton->setObjectName(QString::fromUtf8("StartingSceneSettingsButton"));
        StartingSceneSettingsButton->setGeometry(QRect(820, 582, 280, 100));
        StartingSceneSettingsButton->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"        background-color: transparent;\n"
"        border: none;\n"
"        background-repeat: none;\n"
"        background: none;\n"
"        background-image:url(:/greenLay280x100.png);\n"
"        font-size: 22px;\n"
"        font-family: Comic Sans MS;\n"
"        color: white;\n"
"    }\n"
"    :hover{\n"
"        background-image:url(:/greenLay280x100Highlighted.png);\n"
"    };\n"
"\n"
""));
        stackedWidget->addWidget(StartingScene);
        NewGameScene = new QWidget();
        NewGameScene->setObjectName(QString::fromUtf8("NewGameScene"));
        NewGameSceneLeaguesComboBox = new QComboBox(NewGameScene);
        NewGameSceneLeaguesComboBox->setObjectName(QString::fromUtf8("NewGameSceneLeaguesComboBox"));
        NewGameSceneLeaguesComboBox->setGeometry(QRect(490, 30, 1000, 100));
        NewGameSceneLeaguesComboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"				background-color: transparent;\n"
"                border: none;\n"
"                background-repeat: none;\n"
"                background: none;\n"
"                font-size: 35px;\n"
"                font-family: Comic Sans MS;\n"
"                color: black;\n"
"				text-align: center;\n"
"}\n"
"\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                                stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid darkgray;\n"
"    selection-background-color: lightgray;\n"
"}"));
        NewGameSceneClubName = new QLabel(NewGameScene);
        NewGameSceneClubName->setObjectName(QString::fromUtf8("NewGameSceneClubName"));
        NewGameSceneClubName->setGeometry(QRect(490, 160, 1000, 100));
        NewGameSceneClubName->setStyleSheet(QString::fromUtf8("QLabel{\n"
"                background-color: transparent;\n"
"                border: none;\n"
"                background-repeat: none;\n"
"                background: none;\n"
"                font-size: 35px;\n"
"                font-family: Comic Sans MS;\n"
"                color: white;\n"
"				text-align: center;\n"
"            };\n"
""));
        NewGameSceneClubLogo = new QLabel(NewGameScene);
        NewGameSceneClubLogo->setObjectName(QString::fromUtf8("NewGameSceneClubLogo"));
        NewGameSceneClubLogo->setGeometry(QRect(490, 290, 1000, 200));
        NewGameSceneClubLogo->setAlignment(Qt::AlignCenter);
        NewGameSceneClubInfoLabel = new QLabel(NewGameScene);
        NewGameSceneClubInfoLabel->setObjectName(QString::fromUtf8("NewGameSceneClubInfoLabel"));
        NewGameSceneClubInfoLabel->setGeometry(QRect(490, 500, 1000, 180));
        NewGameSceneClubInfoLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"                background-color: transparent;\n"
"                border: none;\n"
"                background-repeat: none;\n"
"                background: none;\n"
"                font-size: 25px;\n"
"                font-family: Comic Sans MS;\n"
"                color: white;\n"
"            };"));
        NewGameSceneStartButton = new QPushButton(NewGameScene);
        NewGameSceneStartButton->setObjectName(QString::fromUtf8("NewGameSceneStartButton"));
        NewGameSceneStartButton->setGeometry(QRect(790, 740, 400, 120));
        NewGameSceneStartButton->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"            background-color: transparent;\n"
"            border: none;\n"
"            background-repeat: none;\n"
"            background: none;\n"
"            background-image:url(:/greenLay400x120.png);\n"
"            font-size: 40px;\n"
"            font-family: Comic Sans MS;\n"
"            color: white;\n"
"        }\n"
"        :hover{\n"
"            background-image:url(:/greenLay400x120Highlighted.png);\n"
"        };\n"
""));
        NewGameScenePrevClubButton = new QPushButton(NewGameScene);
        NewGameScenePrevClubButton->setObjectName(QString::fromUtf8("NewGameScenePrevClubButton"));
        NewGameScenePrevClubButton->setGeometry(QRect(300, 160, 120, 120));
        NewGameScenePrevClubButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"                background-color: transparent;\n"
"                border: none;\n"
"                background-repeat: none;\n"
"                background: none;\n"
"                background-image:url(:/leftArrow120x120.png);\n"
"            }\n"
"            :hover{\n"
"                background-image:url(:/leftArrowHighlighted120x120.png);\n"
"            };\n"
""));
        NewGameSceneNextClubButton = new QPushButton(NewGameScene);
        NewGameSceneNextClubButton->setObjectName(QString::fromUtf8("NewGameSceneNextClubButton"));
        NewGameSceneNextClubButton->setGeometry(QRect(1560, 160, 120, 120));
        NewGameSceneNextClubButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"                background-color: transparent;\n"
"                border: none;\n"
"                background-repeat: none;\n"
"                background: none;\n"
"                background-image:url(:/rightArrow120x120.png);\n"
"            }\n"
"            :hover{\n"
"                background-image:url(:/rightArrowHighlighted120x120.png);\n"
"            };\n"
""));
        stackedWidget->addWidget(NewGameScene);
        HomeScene = new QWidget();
        HomeScene->setObjectName(QString::fromUtf8("HomeScene"));
        HomeSceneNLTransfers = new QPushButton(HomeScene);
        HomeSceneNLTransfers->setObjectName(QString::fromUtf8("HomeSceneNLTransfers"));
        HomeSceneNLTransfers->setGeometry(QRect(300, 40, 160, 40));
        HomeSceneNLTransfers->setStyleSheet(QString::fromUtf8("QPushButton{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 30px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: left; \n"
"     } \n"
"     :hover{ \n"
"         color: orange; \n"
"     } ;"));
        HomeSceneNLHome = new QPushButton(HomeScene);
        HomeSceneNLHome->setObjectName(QString::fromUtf8("HomeSceneNLHome"));
        HomeSceneNLHome->setGeometry(QRect(900, 40, 90, 40));
        HomeSceneNLHome->setStyleSheet(QString::fromUtf8("QPushButton{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 30px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: left; \n"
"     } \n"
"     :hover{ \n"
"         color: orange; \n"
"     } ;"));
        HomeSceneNLCompetitions = new QPushButton(HomeScene);
        HomeSceneNLCompetitions->setObjectName(QString::fromUtf8("HomeSceneNLCompetitions"));
        HomeSceneNLCompetitions->setGeometry(QRect(1400, 40, 190, 40));
        HomeSceneNLCompetitions->setStyleSheet(QString::fromUtf8("QPushButton{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 30px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: left; \n"
"     } \n"
"     :hover{ \n"
"         color: orange; \n"
"     } ;"));
        HomeSceneSSANation = new QPushButton(HomeScene);
        HomeSceneSSANation->setObjectName(QString::fromUtf8("HomeSceneSSANation"));
        HomeSceneSSANation->setGeometry(QRect(300, 170, 120, 30));
        HomeSceneSSANation->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: center;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        HomeSceneSSAPos = new QPushButton(HomeScene);
        HomeSceneSSAPos->setObjectName(QString::fromUtf8("HomeSceneSSAPos"));
        HomeSceneSSAPos->setGeometry(QRect(830, 170, 90, 30));
        HomeSceneSSAPos->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: central;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        HomeSceneSSAAge = new QPushButton(HomeScene);
        HomeSceneSSAAge->setObjectName(QString::fromUtf8("HomeSceneSSAAge"));
        HomeSceneSSAAge->setGeometry(QRect(930, 170, 81, 30));
        HomeSceneSSAAge->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: central;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        HomeSceneSSAValue = new QPushButton(HomeScene);
        HomeSceneSSAValue->setObjectName(QString::fromUtf8("HomeSceneSSAValue"));
        HomeSceneSSAValue->setGeometry(QRect(1030, 170, 161, 30));
        HomeSceneSSAValue->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: central;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        HomeSceneSSARating = new QPushButton(HomeScene);
        HomeSceneSSARating->setObjectName(QString::fromUtf8("HomeSceneSSARating"));
        HomeSceneSSARating->setGeometry(QRect(1200, 170, 121, 30));
        HomeSceneSSARating->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: central;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        HomeSceneSSA = new QScrollArea(HomeScene);
        HomeSceneSSA->setObjectName(QString::fromUtf8("HomeSceneSSA"));
        HomeSceneSSA->setGeometry(QRect(300, 210, 1020, 600));
        HomeSceneSSA->setStyleSheet(QString::fromUtf8("QScrollArea{\n"
"                 background-color: transparent;\n"
"                 border: none;\n"
"                 background-repeat: none;\n"
"                 background: transparent;\n"
"             }\n"
"             QScrollArea > QWidget > QScrollBar:vertical {\n"
"                 background: palette(base)\n"
"             }\n"
"             QScrollArea > QWidget > QScrollBar:handle:vertical {\n"
"                 background: rgb(141,232,123);\n"
"             }\n"
"             QScrollArea > QWidget > QScrollBar:add-page:vertical {\n"
"                 background: rgb(225,252,220);\n"
"             }\n"
"             QScrollArea > QWidget > QScrollBar:sub-page:vertical {\n"
"                 background: rgb(225,252,220);\n"
"             }"));
        HomeSceneSSA->setWidgetResizable(true);
        HomeSceneSSAWidget = new QWidget();
        HomeSceneSSAWidget->setObjectName(QString::fromUtf8("HomeSceneSSAWidget"));
        HomeSceneSSAWidget->setGeometry(QRect(0, 0, 1020, 600));
        HomeSceneSSAWidget->setStyleSheet(QString::fromUtf8("QScrollArea > QWidget > QWidget{\n"
"                  background-color: transparent;\n"
"                  border: none;\n"
"                  background-repeat: none;\n"
"                  background: transparent;\n"
"              }  ;"));
        HomeSceneSSA->setWidget(HomeSceneSSAWidget);
        HomeSceneSSAName = new QPushButton(HomeScene);
        HomeSceneSSAName->setObjectName(QString::fromUtf8("HomeSceneSSAName"));
        HomeSceneSSAName->setGeometry(QRect(430, 170, 391, 30));
        HomeSceneSSAName->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: central;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        HomeSceneCalendarLabel = new QLabel(HomeScene);
        HomeSceneCalendarLabel->setObjectName(QString::fromUtf8("HomeSceneCalendarLabel"));
        HomeSceneCalendarLabel->setGeometry(QRect(1580, 210, 200, 600));
        stackedWidget->addWidget(HomeScene);
        TransfersScene = new QWidget();
        TransfersScene->setObjectName(QString::fromUtf8("TransfersScene"));
        TransfersSceneNLTransfers = new QPushButton(TransfersScene);
        TransfersSceneNLTransfers->setObjectName(QString::fromUtf8("TransfersSceneNLTransfers"));
        TransfersSceneNLTransfers->setGeometry(QRect(300, 40, 160, 40));
        TransfersSceneNLTransfers->setStyleSheet(QString::fromUtf8("QPushButton{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 30px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: left; \n"
"     } \n"
"     :hover{ \n"
"         color: orange; \n"
"     } ;"));
        TransfersSceneNLHome = new QPushButton(TransfersScene);
        TransfersSceneNLHome->setObjectName(QString::fromUtf8("TransfersSceneNLHome"));
        TransfersSceneNLHome->setGeometry(QRect(900, 40, 90, 40));
        TransfersSceneNLHome->setStyleSheet(QString::fromUtf8("QPushButton{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 30px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: left; \n"
"     } \n"
"     :hover{ \n"
"         color: orange; \n"
"     } ;"));
        TransfersSceneNLCompetitions = new QPushButton(TransfersScene);
        TransfersSceneNLCompetitions->setObjectName(QString::fromUtf8("TransfersSceneNLCompetitions"));
        TransfersSceneNLCompetitions->setGeometry(QRect(1400, 40, 190, 40));
        TransfersSceneNLCompetitions->setStyleSheet(QString::fromUtf8("QPushButton{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 30px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: left; \n"
"     } \n"
"     :hover{ \n"
"         color: orange; \n"
"     } ;"));
        TransfersSceneSSANation = new QPushButton(TransfersScene);
        TransfersSceneSSANation->setObjectName(QString::fromUtf8("TransfersSceneSSANation"));
        TransfersSceneSSANation->setGeometry(QRect(300, 280, 120, 30));
        TransfersSceneSSANation->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: center;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        TransfersSceneSSAName = new QPushButton(TransfersScene);
        TransfersSceneSSAName->setObjectName(QString::fromUtf8("TransfersSceneSSAName"));
        TransfersSceneSSAName->setGeometry(QRect(430, 280, 391, 30));
        TransfersSceneSSAName->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: central;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        TransfersSceneSSAPos = new QPushButton(TransfersScene);
        TransfersSceneSSAPos->setObjectName(QString::fromUtf8("TransfersSceneSSAPos"));
        TransfersSceneSSAPos->setGeometry(QRect(1040, 280, 90, 30));
        TransfersSceneSSAPos->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: central;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        TransfersSceneSSAAge = new QPushButton(TransfersScene);
        TransfersSceneSSAAge->setObjectName(QString::fromUtf8("TransfersSceneSSAAge"));
        TransfersSceneSSAAge->setGeometry(QRect(1140, 280, 81, 30));
        TransfersSceneSSAAge->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: central;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        TransfersSceneSSAValue = new QPushButton(TransfersScene);
        TransfersSceneSSAValue->setObjectName(QString::fromUtf8("TransfersSceneSSAValue"));
        TransfersSceneSSAValue->setGeometry(QRect(1240, 280, 161, 30));
        TransfersSceneSSAValue->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: central;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        TransfersSceneSSARating = new QPushButton(TransfersScene);
        TransfersSceneSSARating->setObjectName(QString::fromUtf8("TransfersSceneSSARating"));
        TransfersSceneSSARating->setGeometry(QRect(1410, 280, 121, 30));
        TransfersSceneSSARating->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: central;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        TransfersSceneSSATeam = new QPushButton(TransfersScene);
        TransfersSceneSSATeam->setObjectName(QString::fromUtf8("TransfersSceneSSATeam"));
        TransfersSceneSSATeam->setGeometry(QRect(830, 280, 200, 30));
        TransfersSceneSSATeam->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             background-repeat: none;\n"
"             background: transparent;\n"
"             font-size: 23px;\n"
"             font-weight: bold;\n"
"             font-family: Comic Sans MS;\n"
"             color: rgb(211, 242, 254);\n"
"             text-align: central;\n"
"         }\n"
"         :hover{\n"
"             color: blue;\n"
"         } ;"));
        TransfersSceneSSA = new QScrollArea(TransfersScene);
        TransfersSceneSSA->setObjectName(QString::fromUtf8("TransfersSceneSSA"));
        TransfersSceneSSA->setGeometry(QRect(300, 320, 1230, 600));
        TransfersSceneSSA->setStyleSheet(QString::fromUtf8("QScrollArea{\n"
"                 background-color: transparent;\n"
"                 border: none;\n"
"                 background-repeat: none;\n"
"                 background: transparent;\n"
"             }\n"
"             QScrollArea > QWidget > QScrollBar:vertical {\n"
"                 background: palette(base)\n"
"             }\n"
"             QScrollArea > QWidget > QScrollBar:handle:vertical {\n"
"                 background: rgb(141,232,123);\n"
"             }\n"
"             QScrollArea > QWidget > QScrollBar:add-page:vertical {\n"
"                 background: rgb(225,252,220);\n"
"             }\n"
"             QScrollArea > QWidget > QScrollBar:sub-page:vertical {\n"
"                 background: rgb(225,252,220);\n"
"             }"));
        TransfersSceneSSA->setWidgetResizable(true);
        TransfersSceneSSAWidget = new QWidget();
        TransfersSceneSSAWidget->setObjectName(QString::fromUtf8("TransfersSceneSSAWidget"));
        TransfersSceneSSAWidget->setGeometry(QRect(0, 0, 1230, 600));
        TransfersSceneSSAWidget->setStyleSheet(QString::fromUtf8("QScrollArea > QWidget > QWidget{\n"
"                  background-color: transparent;\n"
"                  border: none;\n"
"                  background-repeat: none;\n"
"                  background: transparent;\n"
"              }  ;"));
        TransfersSceneSSA->setWidget(TransfersSceneSSAWidget);
        TransfersSceneSearch = new QPushButton(TransfersScene);
        TransfersSceneSearch->setObjectName(QString::fromUtf8("TransfersSceneSearch"));
        TransfersSceneSearch->setGeometry(QRect(1630, 170, 160, 60));
        TransfersSceneSearch->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"                 background-color: transparent;\n"
"                 border: none;\n"
"                 background-repeat: none;\n"
"                 background: none;\n"
"                 background-image:url(:/greenLay160x60.png);\n"
"                 font-size: 24px;\n"
"                 font-family: Comic Sans MS;\n"
"                 color: white;\n"
"             }\n"
"             :hover{\n"
"                 background-image:url(:/greenLay160x60Highlighted.png);\n"
"             };"));
        TransfersSceneFilterFN = new QComboBox(TransfersScene);
        TransfersSceneFilterFN->setObjectName(QString::fromUtf8("TransfersSceneFilterFN"));
        TransfersSceneFilterFN->setGeometry(QRect(300, 130, 171, 30));
        TransfersSceneFilterSN = new QComboBox(TransfersScene);
        TransfersSceneFilterSN->setObjectName(QString::fromUtf8("TransfersSceneFilterSN"));
        TransfersSceneFilterSN->setGeometry(QRect(480, 130, 171, 30));
        TransfersSceneFilterLeague = new QComboBox(TransfersScene);
        TransfersSceneFilterLeague->setObjectName(QString::fromUtf8("TransfersSceneFilterLeague"));
        TransfersSceneFilterLeague->setGeometry(QRect(660, 130, 191, 30));
        TransfersSceneFNLabel = new QLabel(TransfersScene);
        TransfersSceneFNLabel->setObjectName(QString::fromUtf8("TransfersSceneFNLabel"));
        TransfersSceneFNLabel->setGeometry(QRect(300, 110, 171, 20));
        TransfersSceneFNLabel->setStyleSheet(QString::fromUtf8("QLabel{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 14px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: center; \n"
"     } "));
        TransfersSceneSNLabel = new QLabel(TransfersScene);
        TransfersSceneSNLabel->setObjectName(QString::fromUtf8("TransfersSceneSNLabel"));
        TransfersSceneSNLabel->setGeometry(QRect(480, 110, 170, 20));
        TransfersSceneSNLabel->setStyleSheet(QString::fromUtf8("QLabel{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 14px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: center; \n"
"     } "));
        TransfersSceneLeagueLabel = new QLabel(TransfersScene);
        TransfersSceneLeagueLabel->setObjectName(QString::fromUtf8("TransfersSceneLeagueLabel"));
        TransfersSceneLeagueLabel->setGeometry(QRect(660, 110, 191, 20));
        TransfersSceneLeagueLabel->setStyleSheet(QString::fromUtf8("QLabel{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 14px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: center; \n"
"     } "));
        TransfersSceneFilterTeam = new QComboBox(TransfersScene);
        TransfersSceneFilterTeam->setObjectName(QString::fromUtf8("TransfersSceneFilterTeam"));
        TransfersSceneFilterTeam->setGeometry(QRect(860, 130, 191, 30));
        TransfersSceneTeamLabel = new QLabel(TransfersScene);
        TransfersSceneTeamLabel->setObjectName(QString::fromUtf8("TransfersSceneTeamLabel"));
        TransfersSceneTeamLabel->setGeometry(QRect(860, 110, 191, 20));
        TransfersSceneTeamLabel->setStyleSheet(QString::fromUtf8("QLabel{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 14px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: center; \n"
"     } "));
        TransfersSceneFilterMainPos = new QComboBox(TransfersScene);
        TransfersSceneFilterMainPos->setObjectName(QString::fromUtf8("TransfersSceneFilterMainPos"));
        TransfersSceneFilterMainPos->setGeometry(QRect(1060, 130, 71, 30));
        TransfersSceneMainPosLabel = new QLabel(TransfersScene);
        TransfersSceneMainPosLabel->setObjectName(QString::fromUtf8("TransfersSceneMainPosLabel"));
        TransfersSceneMainPosLabel->setGeometry(QRect(1060, 89, 71, 41));
        TransfersSceneMainPosLabel->setStyleSheet(QString::fromUtf8("QLabel{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 14px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: center; \n"
"     } "));
        TransfersSceneFilterSecondPos = new QComboBox(TransfersScene);
        TransfersSceneFilterSecondPos->setObjectName(QString::fromUtf8("TransfersSceneFilterSecondPos"));
        TransfersSceneFilterSecondPos->setGeometry(QRect(1140, 130, 71, 30));
        TransfersSceneSecondPosLabel = new QLabel(TransfersScene);
        TransfersSceneSecondPosLabel->setObjectName(QString::fromUtf8("TransfersSceneSecondPosLabel"));
        TransfersSceneSecondPosLabel->setGeometry(QRect(1140, 90, 71, 41));
        TransfersSceneSecondPosLabel->setStyleSheet(QString::fromUtf8("QLabel{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 14px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: center; \n"
"     } "));
        TransfersSceneFilterMinAge = new QLineEdit(TransfersScene);
        TransfersSceneFilterMinAge->setObjectName(QString::fromUtf8("TransfersSceneFilterMinAge"));
        TransfersSceneFilterMinAge->setGeometry(QRect(1220, 130, 41, 30));
        TransfersSceneMinAgeLabel = new QLabel(TransfersScene);
        TransfersSceneMinAgeLabel->setObjectName(QString::fromUtf8("TransfersSceneMinAgeLabel"));
        TransfersSceneMinAgeLabel->setGeometry(QRect(1220, 90, 41, 41));
        TransfersSceneMinAgeLabel->setStyleSheet(QString::fromUtf8("QLabel{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 14px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: center; \n"
"     } "));
        TransfersSceneFilterMaxAge = new QLineEdit(TransfersScene);
        TransfersSceneFilterMaxAge->setObjectName(QString::fromUtf8("TransfersSceneFilterMaxAge"));
        TransfersSceneFilterMaxAge->setGeometry(QRect(1270, 130, 41, 30));
        TransfersSceneMaxAgeLabel = new QLabel(TransfersScene);
        TransfersSceneMaxAgeLabel->setObjectName(QString::fromUtf8("TransfersSceneMaxAgeLabel"));
        TransfersSceneMaxAgeLabel->setGeometry(QRect(1270, 90, 41, 41));
        TransfersSceneMaxAgeLabel->setStyleSheet(QString::fromUtf8("QLabel{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 14px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: center; \n"
"     } "));
        TransfersSceneFilterMinSkill = new QLineEdit(TransfersScene);
        TransfersSceneFilterMinSkill->setObjectName(QString::fromUtf8("TransfersSceneFilterMinSkill"));
        TransfersSceneFilterMinSkill->setGeometry(QRect(1320, 130, 41, 30));
        TransfersSceneMinSkillLabel = new QLabel(TransfersScene);
        TransfersSceneMinSkillLabel->setObjectName(QString::fromUtf8("TransfersSceneMinSkillLabel"));
        TransfersSceneMinSkillLabel->setGeometry(QRect(1320, 90, 41, 41));
        TransfersSceneMinSkillLabel->setStyleSheet(QString::fromUtf8("QLabel{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 14px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: center; \n"
"     } "));
        TransfersSceneFilterMaxSkill = new QLineEdit(TransfersScene);
        TransfersSceneFilterMaxSkill->setObjectName(QString::fromUtf8("TransfersSceneFilterMaxSkill"));
        TransfersSceneFilterMaxSkill->setGeometry(QRect(1370, 130, 41, 30));
        TransfersSceneMaxSkillLabel = new QLabel(TransfersScene);
        TransfersSceneMaxSkillLabel->setObjectName(QString::fromUtf8("TransfersSceneMaxSkillLabel"));
        TransfersSceneMaxSkillLabel->setGeometry(QRect(1370, 90, 41, 41));
        TransfersSceneMaxSkillLabel->setStyleSheet(QString::fromUtf8("QLabel{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 14px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: center; \n"
"     } "));
        TransfersSceneFilterSearchName = new QLineEdit(TransfersScene);
        TransfersSceneFilterSearchName->setObjectName(QString::fromUtf8("TransfersSceneFilterSearchName"));
        TransfersSceneFilterSearchName->setGeometry(QRect(300, 210, 251, 30));
        TransfersSceneSearchNameLabel = new QLabel(TransfersScene);
        TransfersSceneSearchNameLabel->setObjectName(QString::fromUtf8("TransfersSceneSearchNameLabel"));
        TransfersSceneSearchNameLabel->setGeometry(QRect(300, 190, 251, 20));
        TransfersSceneSearchNameLabel->setStyleSheet(QString::fromUtf8("QLabel{  \n"
"         background-color: transparent; \n"
"         border: none; \n"
"         background-repeat: none; \n"
"         background: transparent; \n"
"         font-size: 14px; \n"
"         font-weight: bold; \n"
"         font-family: Comic Sans MS; \n"
"         color: rgb(211, 242, 254); \n"
"         text-align: center; \n"
"     } "));
        stackedWidget->addWidget(TransfersScene);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        StartingSceneNewGame->setText(QCoreApplication::translate("MainWindow", "New game", nullptr));
        StartingSceneLoadGame->setText(QCoreApplication::translate("MainWindow", "Load game", nullptr));
        StartingSceneSettingsButton->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        NewGameSceneClubName->setText(QCoreApplication::translate("MainWindow", "CLUB NAME ", nullptr));
        NewGameSceneClubLogo->setText(QString());
        NewGameSceneClubInfoLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        NewGameSceneStartButton->setText(QCoreApplication::translate("MainWindow", "Start game!", nullptr));
        NewGameScenePrevClubButton->setText(QString());
        NewGameSceneNextClubButton->setText(QString());
        HomeSceneNLTransfers->setText(QCoreApplication::translate("MainWindow", "Transfers", nullptr));
        HomeSceneNLHome->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        HomeSceneNLCompetitions->setText(QCoreApplication::translate("MainWindow", "Competitions", nullptr));
        HomeSceneSSANation->setText(QCoreApplication::translate("MainWindow", "Nation", nullptr));
        HomeSceneSSAPos->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        HomeSceneSSAAge->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        HomeSceneSSAValue->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        HomeSceneSSARating->setText(QCoreApplication::translate("MainWindow", "Rating", nullptr));
        HomeSceneSSAName->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        HomeSceneCalendarLabel->setText(QString());
        TransfersSceneNLTransfers->setText(QCoreApplication::translate("MainWindow", "Transfers", nullptr));
        TransfersSceneNLHome->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        TransfersSceneNLCompetitions->setText(QCoreApplication::translate("MainWindow", "Competitions", nullptr));
        TransfersSceneSSANation->setText(QCoreApplication::translate("MainWindow", "Nation", nullptr));
        TransfersSceneSSAName->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        TransfersSceneSSAPos->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        TransfersSceneSSAAge->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        TransfersSceneSSAValue->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        TransfersSceneSSARating->setText(QCoreApplication::translate("MainWindow", "Rating", nullptr));
        TransfersSceneSSATeam->setText(QCoreApplication::translate("MainWindow", "Team", nullptr));
        TransfersSceneSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        TransfersSceneFilterFN->setCurrentText(QString());
        TransfersSceneFilterFN->setPlaceholderText(QString());
        TransfersSceneFNLabel->setText(QCoreApplication::translate("MainWindow", "First nationality", nullptr));
        TransfersSceneSNLabel->setText(QCoreApplication::translate("MainWindow", "Second nationality", nullptr));
        TransfersSceneLeagueLabel->setText(QCoreApplication::translate("MainWindow", "League", nullptr));
        TransfersSceneTeamLabel->setText(QCoreApplication::translate("MainWindow", "Team", nullptr));
        TransfersSceneMainPosLabel->setText(QCoreApplication::translate("MainWindow", "Main \n"
"position", nullptr));
        TransfersSceneSecondPosLabel->setText(QCoreApplication::translate("MainWindow", "Second \n"
"position", nullptr));
        TransfersSceneFilterMinAge->setText(QString());
        TransfersSceneMinAgeLabel->setText(QCoreApplication::translate("MainWindow", "Min \n"
"age", nullptr));
        TransfersSceneFilterMaxAge->setText(QString());
        TransfersSceneMaxAgeLabel->setText(QCoreApplication::translate("MainWindow", "Max \n"
"age", nullptr));
        TransfersSceneFilterMinSkill->setText(QString());
        TransfersSceneMinSkillLabel->setText(QCoreApplication::translate("MainWindow", "Min \n"
"skill", nullptr));
        TransfersSceneFilterMaxSkill->setText(QString());
        TransfersSceneMaxSkillLabel->setText(QCoreApplication::translate("MainWindow", "Max \n"
"skill", nullptr));
        TransfersSceneSearchNameLabel->setText(QCoreApplication::translate("MainWindow", "Search by name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
