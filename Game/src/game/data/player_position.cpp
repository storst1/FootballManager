#include "player_position.h"

PLAYER_POSITION::PLAYER_POSITION()
{

}

PLAYER_POSITION::PLAYER_POSITION(int fp) : FP(fp)
{

}

PLAYER_POSITION::PLAYER_POSITION(int fp, int sp) : FP(fp), SP(sp)
{

}

PLAYER_POSITION::PLAYER_POSITION(int fp, int sp, QString name) :
    FP(fp), SP(sp), strName(name)
{

}

int PLAYER_POSITION::getFP() const
{
    return FP;
}

int PLAYER_POSITION::getSP() const
{
    return SP;
}

QString PLAYER_POSITION::getStrName() const
{
    return strName;
}
