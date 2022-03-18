#ifndef TABLE_H
#define TABLE_H

#include "game/data/data_defs.h"
#include "game/data/club.h"

class POSITION{
public:
    POSITION();
    ~POSITION() = default;
private:
    int pos;
};

class TABLE
{
public:
    TABLE();
    ~TABLE();

    QList<POSITION*> getTable();
private:
    QList<POSITION*> standings;
};

#endif // TABLE_H