#ifndef TEAM_H
#define TEAM_H

#include "game/data/data_defs.h"

class COACH;
class PLAYER;

class TEAM
{
public:
    TEAM();
    ~TEAM();

protected:
    QString name;
    QList<PLAYER*> players;
    COACH* coach;
};

#endif // TEAM_H
