#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,
         this, [=](QNetworkReply *reply) {
              if (reply->error()) {
                qDebug() << reply->errorString();
                 return;
             }

             QString answer = reply->readAll();

             qDebug() << answer;
          }
    );
}

MainWindow::~MainWindow()
{
    delete manager;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    request.setUrl(QUrl("https://transfermarket.p.rapidapi.com/clubs/get-profile?id=1"));
    request.setRawHeader("x-rapidapi-host", "transfermarket.p.rapidapi.com");
    request.setRawHeader("x-rapidapi-key", "b9f7af25f5msh32a9cb7f56a4119p1d835ejsnd02ec50257bf");
    manager->get(request);
}

