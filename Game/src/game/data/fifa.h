#ifndef FIFA_H
#define FIFA_H

#include "game/data/data_defs.h"

class FIFA
{
public:
    FIFA();
    ~FIFA();
private:
    CONFEDERATION* CAF;
    CONFEDERATION* AFC;
    CONFEDERATION* UEFA;
    CONFEDERATION* CONCACAF;
    CONFEDERATION* OFC;
    CONFEDERATION* CONMEBOL;

    QVector<FEDERATION*> fifaRating;
};

#endif // FIFA_H
