#include "game/data/stadium.h"

STADIUM::STADIUM()
{

}

STADIUM::STADIUM(QString name, int capacity) : name(name), capacity(capacity)
{

}

int STADIUM::getCapacity() const
{
    return capacity;
}

QString STADIUM::getName() const
{
    return name;
}

void STADIUM::NormalizeStadiumCapacity(int &capacity)
{
    if(capacity == 0){
        int randCap = QRandomGenerator::global()->bounded(1, 10);
        capacity = randCap * 1000;
    }
}
