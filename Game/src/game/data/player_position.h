#ifndef PLAYER_POSITION_H
#define PLAYER_POSITION_H

#include "game/data/data_defs.h"

class PLAYER_POSITION
{
public:
    PLAYER_POSITION();
    ~PLAYER_POSITION() = default;
private:
    int FP;
    int SP;
    QString strName;
};

#endif // PLAYER_POSITION_H
