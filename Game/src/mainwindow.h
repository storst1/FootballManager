#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database_real_data.h"
#include "network_manager.h"

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
    void SetupNetworkManager();
    void SetupDb();
    void CollectData();
    void FillAllLeagues();
    void FillAllLeaguesWithBaseInfo();
    void FillAllPlayers();
    QList<CLUB*> InitClubs(QList<CLUB> clubList);
    void SaveAllData(QList<LEAGUE*> leagues, QList<CLUB*> clubs, QList<PLAYER*> players);
    void LoadAllDataFromAPI();
    void LoadAllDataFromDB();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    DATABASE_REAL_DATA* realDataDb;
    NETWORK_MANAGER* netManager;
    QList<LEAGUE*> allLeagues;
    QList<CLUB*> allClubs;
    QList<PLAYER*> allPlayers;
};
#endif // MAINWINDOW_H
