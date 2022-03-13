#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetupDb();
    SetupNetworkManager();
    //allLeagues = realDataDb->getAllLeagues();
}

MainWindow::~MainWindow()
{
    delete manager;
    delete ui;
}

QString MainWindow::getRealDataDbPath()
{
    qDebug() << qApp->applicationDirPath();
    QString path = qApp->applicationDirPath();
    int cnt = 0;
    int i = path.length() - 1;
    while(cnt < 3){
        if(path[i] == '/'){
            ++cnt;
        }
        --i;
    }
    path.erase(path.cbegin() + i + 1, path.cend());
    qDebug() << path;
    path += "/Databases/realdata.db";
    return path;
}

void MainWindow::SetupNetworkManager()
{
    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply)
    {
         if (reply->error()) {
            qDebug() << reply->errorString();
            return;
         }
         RequestBuffer = reply->readAll();
         qDebug() << RequestBuffer;
        }
    );
}

void MainWindow::SetupDb()
{
    QString dbPath = getRealDataDbPath();
    realDataDb = new DATABASE(dbPath);
}


void MainWindow::on_pushButton_clicked()
{
    CollectData();
    request.setUrl(QUrl("https://transfermarket.p.rapidapi.com/clubs/get-profile?id=1"));
    request.setRawHeader("x-rapidapi-host", "transfermarket.p.rapidapi.com");
    request.setRawHeader("x-rapidapi-key", "b9f7af25f5msh32a9cb7f56a4119p1d835ejsnd02ec50257bf");
    manager->get(request);
}

