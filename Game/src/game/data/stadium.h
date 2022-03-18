#ifndef STADIUM_H
#define STADIUM_H

#include "game/data/data_defs.h"

class STADIUM
{
public:
    STADIUM();
    ~STADIUM() = default;

    int getCapacity() const;
private:
    int capacity;
};

#endif // STADIUM_H
