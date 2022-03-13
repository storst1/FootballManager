#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database.h"
#include "request_buffer.h"

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>

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
    QString GatherLeagueName(const QString& leagueId);
    void SetupRequestAuth();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager* manager;
    QNetworkRequest request;
    DATABASE* realDataDb;
    REQUEST_BUFFER* RequestBuffer;
    QList<LEAGUE*> allLeagues;
};
#endif // MAINWINDOW_H
