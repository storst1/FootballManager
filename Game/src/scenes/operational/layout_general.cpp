#include "main/mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::SetupMainLay(){
    QPixmap background(":/backgroundCutSizeLessBright.jpg");
    _width = QGuiApplication::primaryScreen()->geometry().width();
    _height = QGuiApplication::primaryScreen()->geometry().height();
    qDebug() << "QGuiApplication::primaryScreen->geometry() == {" << _width << ", " << _height << "}";
    background = background.scaled(_width, _height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    setPalette(palette);

    mainLay = new QGridLayout();
    //ui->centralwidget->setLayout(mainLay);
    mainWidget = new QStackedWidget();
    mainWidget->setFixedSize(_width, _height);
    mainLay->addWidget(mainWidget);
    sceneSwitch = new SCENE_SWITCH(mainWidget);
    //qDebug() << _width << " " << _height;
    InitAllScenes();
}

void MainWindow::PushBackEmptyToLay(int amount)
{
    while(amount--){
        mainLay->addWidget(new QLabel(""));
    }
}

void MainWindow::PushBackEmptyToLay(QGridLayout* lay, int amount)
{
    while(amount--){
        lay->addWidget(new QLabel(""));
    }
}

void MainWindow::TakeSpaceInLay(int h)
{
    QLabel* label = new QLabel("");
    label->setFixedHeight(h);
    mainLay->addWidget(label);
}

void MainWindow::TakeSpaceInLay(QGridLayout *lay, int h)
{
    QLabel* label = new QLabel("");
    label->setFixedHeight(h);
    lay->addWidget(label);
}

void MainWindow::TakeSpaceInLay(int h, int row, int col_amount)
{
    for(int i = 0; i < col_amount; ++i){
        QLabel* label = new QLabel("");
        label->setFixedHeight(h);
        mainLay->addWidget(label, row, i);
    }
}

void MainWindow::TakeSpaceInLay(QGridLayout *lay, int h, int row, int col_amount)
{
    for(int i = 0; i < col_amount; ++i){
        QLabel* label = new QLabel("");
        label->setFixedHeight(h);
        lay->addWidget(label, row, i);
    }
}

void MainWindow::ClearLay()
{
    ClearLay(mainLay);
}

void MainWindow::ClearLay(QGridLayout *lay)
{
    if(lay == nullptr){
        return;
    }
    QLayoutItem* curItem;
    //qDebug() << "Entered ClearLay() with lay consist of " << lay->count() << " items";
    while(lay->count()){
        curItem = lay->takeAt(0);
        if(curItem == nullptr){
            continue;
        }
        //qDebug() << "Entered while, i = " << i;
        if(curItem->layout() != nullptr){
            ClearLay(dynamic_cast<QGridLayout*>(curItem->layout()));
            //qDebug() << "Deleted lay: " << curItem->layout();
            //TO DO: Figure out if following line leads to memory leak or is it supposed to work like that
            //delete curItem->layout();
        }
        else if(curItem->widget() != nullptr){
            //qDebug() << "Deleted widget: " << curItem->widget() << " i = " << i;
            curItem->widget()->hide();
            //curItem->widget()->deleteLater();
            delete curItem->widget();
        }
        //qDebug() << "Trying to delete item: " << curItem;
        //else {
        //TO DO: Figure out if following line leads to memory leak or is it supposed to work like that
        //delete curItem;
        //}
    }
    //qDebug() << "ClearLay() finished working";
}

QLabel* MainWindow::NewTrashPtr()
{
    return new QLabel("");
}

void MainWindow::drawPlayerFlag(QPixmap &flag, FEDERATION *fed1, FEDERATION *fed2)
{
    if(fed1->getFlag() == nullptr){
        qDebug() << "No flag of fed with id = " << fed1->getId();
        return;
    }
    flag.fill(Qt::transparent);
    QPainter painter(&flag);
    painter.drawPixmap(0, 5, 48, 30, *fed1->getFlag());
    if(fed2 != nullptr){
        if(fed2->getFlag() == nullptr){
            qDebug() << "No flag of fed with id = " << fed2->getId();
            painter.end();
            return;
        }
        painter.drawPixmap(55, 9, 35, 22, *fed2->getFlag());
    }
    painter.end();
}

void MainWindow::drawLeagueHeaderFlag(QPixmap &flag, FEDERATION *fed)
{
    if(fed->getFlag() == nullptr){
        qDebug() << "No flag of fed with id = " << fed->getId();
        return;
    }
    flag.fill(Qt::transparent);
    QPainter painter(&flag);
    painter.drawPixmap(0, 5, 48, 30, *fed->getFlag());
    painter.end();
}

void MainWindow::SetupNavigationLay(){
    if(navigationLay){
        ClearLay(navigationLay);
        delete navigationLay;
    }
    navigationLay = new QGridLayout();

    QString navigationButtonStyle =
            "QPushButton{ "
                "background-color: transparent;"
                "border: none;"
                "background-repeat: none;"
                "background: transparent;"
                "font-size: 30px;"
                "font-weight: bold;"
                "font-family: Comic Sans MS;"
                "color: rgb(211, 242, 254);"
                "text-align: left;"
            "}"
            ":hover{"
                "color: orange;"
            "}";

    const int navigationHeight = 80;

    navigationHomeButton = new QPushButton("Home");
    navigationHomeButton->setStyleSheet(navigationButtonStyle);
    navigationHomeButton->setFixedSize(200, navigationHeight);
    connect(navigationHomeButton, &QPushButton::clicked, this, [this]{
        //Temporary solution to make debugging easier
        SetupNewGameScene();
        //SetupHomeScene();
    });

    navigationTransfersButton = new QPushButton("Transfers");
    navigationTransfersButton->setStyleSheet(navigationButtonStyle);
    navigationTransfersButton->setFixedSize(200, navigationHeight);
    connect(navigationTransfersButton, &QPushButton::clicked, this, [this]{
        SetupTransfersScene();
    });

    navigationTournamentsButton = new QPushButton("Tournaments");
    navigationTournamentsButton->setStyleSheet(navigationButtonStyle);
    navigationTournamentsButton->setFixedSize(200, navigationHeight);

    navigationLay->addWidget(navigationHomeButton, 0, 0);
    navigationLay->addWidget(navigationTransfersButton, 0, 1);
    navigationLay->addWidget(navigationTournamentsButton, 0, 2);
}

void MainWindow::MoveWidgetToFitRes(QWidget *widget) noexcept
{
    const float orig_x = widget->pos().x();
    const float orig_y = widget->pos().y();
    float res_diff_x = (float)_width / 1980.f;
    float res_diff_y = (float)_height / 1024.f;
    float new_x = orig_x * res_diff_x;
    float new_y = orig_y * res_diff_y;
    widget->move(new_x, new_y);
}


//Adjusts positions of all the children of provided @widget
void MainWindow::MoveAllChildWidgetsToFitRes(QWidget *widget) noexcept
{
    QList<QObject*> list = widget->findChildren<QObject*>();
    foreach(QObject* children_obj, list){
        //Assuming all the children objects are widgets
        QWidget* children_widget = dynamic_cast<QWidget*>(children_obj);
        MoveAllChildWidgetsToFitRes(children_widget);
    }
}

void MainWindow::MoveMultipleWidgetsToFitRes(std::initializer_list<QWidget *> widgets)
{
    for(QWidget* widget : widgets){
        MoveWidgetToFitRes(widget);
    }
}

void MainWindow::ResizeWidgetToFitRes(QWidget *widget)
{
    float res_diff_x = (float)_width / 1980.f;
    float res_diff_y = (float)_height / 1024.f;
    if(auto push_button = qobject_cast<QPushButton*>(widget)){
        ResizePB(push_button, res_diff_x, res_diff_y);
    }
    else if(auto combo_box = qobject_cast<QComboBox*>(widget)){
        ResizeComboBox(combo_box, res_diff_x, res_diff_y);
    }
    else if(auto label = qobject_cast<QLabel*>(widget)){
        ResizeLabel(label, res_diff_x, res_diff_y);
    }
}

void MainWindow::ResizePB(QPushButton *PB, float x_mult, float y_mult)
{
     ResizeGeneralWidget(PB, x_mult, y_mult);
}

void MainWindow::ResizeComboBox(QComboBox *CB, float x_mult, float y_mult)
{
    ResizeGeneralWidget(CB, x_mult, y_mult);
}

void MainWindow::ResizeLabel(QLabel *label, float x_mult, float y_mult)
{
    ResizeGeneralWidget(label, x_mult, y_mult);

    QPixmap pixmap = label->pixmap();
    QPixmap new_pixmap = pixmap.scaled(pixmap.width() * x_mult, pixmap.height() * y_mult, Qt::IgnoreAspectRatio);
    label->setPixmap(new_pixmap);
}

void MainWindow::ResizeGeneralWidget(QWidget *widget, float x_mult, float y_mult)
{
    float min_mult = std::min(x_mult, y_mult);

    //Resize font
    QFont cur_font = widget->font();
    float font_size = cur_font.pointSizeF();
    float new_font_size = font_size * min_mult;
    cur_font.setPointSizeF(new_font_size);
    widget->setFont(cur_font);

    //Adjust geometry
    float width = widget->width();
    float height = widget->height();
    float new_width = width * x_mult;
    float new_height = height * y_mult;
    widget->setGeometry(widget->x(), widget->y(), new_width, new_height);
}

void MainWindow::ResizeMultWidgetsToFitRes(std::initializer_list<QWidget *> widgets)
{
    for(QWidget* widget : widgets){
        ResizeWidgetToFitRes(widget);
    }
}

/*
template<class... Args>
void MainWindow::MoveMultipleWidgetsToFitRes(Args... args)
{

}
*/
