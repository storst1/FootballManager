#ifndef COACH_H
#define COACH_H

#include "game/data/data_defs.h"

class COACH
{
public:
    COACH();
    ~COACH() = default;

private:
    int id;
    QString name;
    int age;
};

#endif // COACH_H
