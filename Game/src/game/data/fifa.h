#ifndef FIFA_H
#define FIFA_H

#include "game/data/data_defs.h"

class CONFEDERATION;
class FEDERATION;

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
