#include "scene_switch.h"

SCENE_SWITCH::SCENE_SWITCH(QStackedWidget* widget) : widget(widget)
{

}

SCENE_SWITCH::~SCENE_SWITCH()
{

}

void SCENE_SWITCH::Switch(int idx)
{
    if(!history.empty() && idx == history.back()){
        return;
    }
    widget->setCurrentIndex(idx);
    history.push_back(idx);
    if(history.size() > 30){
        history.pop_front();
    }
}

void SCENE_SWITCH::Back()
{
    if(history.size() < 2){
        return;
    }
    history.pop_back();
    widget->setCurrentIndex(history.size() - 1);
}
