#include "main/mainwindow.h"
#include "ui_mainwindow.h"


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
    if(pixmap.isNull()){
        return;
    }
    QPixmap new_pixmap = pixmap.scaled(pixmap.width() * x_mult, pixmap.height() * y_mult, Qt::IgnoreAspectRatio);
    label->setPixmap(new_pixmap);
}

void MainWindow::ResizeGeneralWidget(QWidget *widget, float x_mult, float y_mult)
{
    float min_mult = std::min(x_mult, y_mult);

    //Resize font
    QFont cur_font = widget->font();
    float font_size = cur_font.pixelSize();
    if(font_size > 0.1f){
        float new_font_size = font_size * min_mult;
        cur_font.setPixelSize(new_font_size);
        widget->setFont(cur_font);
    }

    //Adjust geometry
    float width = widget->width();
    float height = widget->height();
    float new_width = width * x_mult;
    float new_height = height * y_mult;
    widget->setGeometry(widget->x(), widget->y(), new_width, new_height);
}

void MainWindow::ResizeMultipleWidgetsToFitRes(std::initializer_list<QWidget *> widgets)
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
