#ifndef CONFEDERATION_H
#define CONFEDERATION_H

#include "game/data/data_defs.h"

class FEDERATION;

class CONFEDERATION
{
public:
    CONFEDERATION();
    ~CONFEDERATION();
private:
    QString name;
    QList<FEDERATION*> fedList;
};

#endif // CONFEDERATION_H
