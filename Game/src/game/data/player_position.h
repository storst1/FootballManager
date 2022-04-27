#ifndef PLAYER_POSITION_H
#define PLAYER_POSITION_H

#include "game/data/data_defs.h"

class PLAYER_POSITION
{
public:
    PLAYER_POSITION();
    PLAYER_POSITION(int fp);
    PLAYER_POSITION(int fp, int sp);
    PLAYER_POSITION(int fp, int sp, QString name);
    ~PLAYER_POSITION() = default;

    static QString posIdToStr(int id);

    int getFP() const;
    int getSP() const;
    QString getStrName() const;

    void setStrNameToAuto();
    static void NormalizeBothPosId(int& pos1, int& pos2);
    static void NormalizePosId(int& pos, bool mainPos);
private:
    int FP;
    int SP;
    QString strName;
};

#endif // PLAYER_POSITION_H
