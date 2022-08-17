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
        HomeSceneNLTransfers->setGeometry(QRect(300, 40, 161, 40));
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
        HomeSceneNLHome->setGeometry(QRect(900, 40, 91, 40));
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
        HomeSceneNLCompetitions->setGeometry(QRect(1400, 40, 191, 40));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
