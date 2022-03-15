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

PLAYER::PLAYER(int id, QString name, int TW, int FN, int SN, int FP, int SP, QString height, int age, int club)
    : id(id), name(name), TW(TW), FN(FN), SN(SN), FP(FP), SP(SP), height(height), age(age), club_id(club)
{

}

void PLAYER::setClubId(int id)
{
    club_id = id;
}

int PLAYER::getId() const
{
    return id;
}

QString PLAYER::getHeight() const
{
    return height;
}

QString PLAYER::getName() const
{
    return name;
}

int PLAYER::getAge() const
{
    return age;
}

int PLAYER::getFN() const
{
    return FN;
}

int PLAYER::getSN() const
{
    return SN;
}

int PLAYER::getFP() const
{
    return FP;
}

int PLAYER::getSP() const
{
    return SP;
}

int PLAYER::getTW() const
{
    return TW;
}

int PLAYER::getClubId() const
{
    return club_id;
}

float PLAYER::getSkill() const
{
    return skill;
}

void PLAYER::recountSkill()
{

}
