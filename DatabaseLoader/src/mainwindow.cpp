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
    delete realDataDb;
    delete manager;
    delete ui;
    qDeleteAll(allLeagues);
    delete RequestBuffer;
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
    RequestBuffer = new REQUEST_BUFFER();
    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply)
    {
         if (reply->error()) {
            qDebug() << "Reply error: " + reply->errorString();
            return;
         }
         RequestBuffer->setBuffer(QString(reply->readAll()));
         qDebug() << RequestBuffer->getBufferRef();
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
    SetupRequestAuth();
    CollectData();
}

void MainWindow::SetupRequestAuth()
{
    request.setRawHeader("x-rapidapi-host", "transfermarket.p.rapidapi.com");
    request.setRawHeader("x-rapidapi-key", "b9f7af25f5msh32a9cb7f56a4119p1d835ejsnd02ec50257bf");
}
