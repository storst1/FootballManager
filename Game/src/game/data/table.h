#ifndef TABLE_H
#define TABLE_H

#include "game/data/data_defs.h"

class POSITION{
public:
    POSITION();
    ~POSITION() = default;
private:
    int pts;
};

class TABLE
{
public:
    TABLE();
    ~TABLE();

    QVector<POSITION*> getTable();
private:
    QVector<POSITION*> standings;
};

#endif // TABLE_H
