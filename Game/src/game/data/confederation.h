#ifndef CONFEDERATION_H
#define CONFEDERATION_H

//#include "federation.h"

#include "data_defs.h"
#include "federation.h"

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
