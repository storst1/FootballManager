#ifndef STADIUM_H
#define STADIUM_H

#include "game/data/data_defs.h"

class STADIUM
{
public:
    STADIUM();
    STADIUM(QString name, int capacity);
    ~STADIUM() = default;

    int getCapacity() const;
    QString getName() const;

    static void NormalizeStadiumCapacity(int& capacity);
private:
    QString name;
    int capacity;
};

#endif // STADIUM_H
