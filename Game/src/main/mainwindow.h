#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database/database_real_data.h"
#include "database/database_skill_converter.h"
#include "network/network_manager.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString getRealDataDbPath();
    QString getDbFolderPath();
    void SetupNetworkManager();
    void SetupDb();
    void CollectData();
    void FillAllLeagues();
    void FillAllLeaguesWithBaseInfo();
    void FillAllPlayers();
    QList<API_CLUB*> InitClubs(QList<API_CLUB> clubList);
    void SaveAllData(QList<API_LEAGUE*> leagues, QList<API_CLUB*> clubs, QList<API_PLAYER*> players);
    void LoadAllDataFromAPI();
    void LoadAllDataFromDB();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    DATABASE_REAL_DATA* realDataDb;
    DATABASE_SKILL_CONVERTER* skillConvDb;
    NETWORK_MANAGER* netManager;
    QList<API_LEAGUE*> allLeagues;
    QList<API_CLUB*> allClubs;
    QList<API_PLAYER*> allPlayers;
};
#endif // MAINWINDOW_H