#include "player.h"

PLAYER::PLAYER()
{

}

PLAYER::PLAYER(int id, QString name, int TW, int FNid, int SNid, QString height)
    : id(id), name(name), TW(TW), FN(FNid), SN(SNid), height(height)
{

}

PLAYER::PLAYER(JSON_PARSER_PLAYER playerInfo)
{
    name = playerInfo.getName();
    id = playerInfo.getId();
    height = playerInfo.getHeight();
    age = playerInfo.getAge();
    FN = playerInfo.getFN();
    SN = playerInfo.getSN();
    FP = playerInfo.getFP();
    SP = playerInfo.getSP();
    TW = playerInfo.getTW();
}
