#ifndef SCENE_SWITCH_H
#define SCENE_SWITCH_H

#include <QVector>
#include <QWidget>
#include <QStackedWidget>
#include <QGridLayout>

class SCENE_SWITCH
{
public:
    SCENE_SWITCH(QStackedWidget* widget);
    ~SCENE_SWITCH();

    void Switch(int idx);
    void Back();
private:
    QStackedWidget* widget;
    QVector<int> history = {};
};

#endif // SCENE_SWITCH_H
