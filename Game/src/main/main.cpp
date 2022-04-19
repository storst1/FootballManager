#include "main/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/IconActualPng.png"));
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    return a.exec();
}
