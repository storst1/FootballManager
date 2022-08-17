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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
