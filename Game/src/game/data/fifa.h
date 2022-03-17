#pragma once
#ifndef FIFA_H
#define FIFA_H

#include "game/data/data_defs.h"
#include "game/data/confederation.h"

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

    QList<FEDERATION*> fifaRating;
};

#endif // FIFA_H
