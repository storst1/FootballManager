#include "stadium.h"

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
