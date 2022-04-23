#include "api/api_player.h"

API_PLAYER::API_PLAYER()
{

}

API_PLAYER::API_PLAYER(int id, QString name, int TW, int FNid, int SNid, QString height)
    : id(id), name(name), TW(TW), FN(FNid), SN(SNid), height(height)
{

}

API_PLAYER::API_PLAYER(JSON_PARSER_PLAYER playerInfo)
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
    Tm_Birthday = playerInfo.getBirthday_TmType();
    Tm_ContractExp = playerInfo.getContractExp_TmType();
}

API_PLAYER::API_PLAYER(int id,
                       QString name,
                       int TW,
                       int FN,
                       int SN,
                       int FP,
                       int SP,
                       QString height,
                       int age,
                       int club,
                       int bd,
                       int contrExp)
    : id(id),
      name(name),
      TW(TW),
      FN(FN),
      SN(SN),
      FP(FP),
      SP(SP),
      height(height),
      age(age),
      club_id(club),
      Tm_Birthday(bd),
      Tm_ContractExp(contrExp)
{

}

void API_PLAYER::setClubId(int id)
{
    club_id = id;
}

int API_PLAYER::getId() const
{
    return id;
}

QString API_PLAYER::getHeight() const
{
    return height;
}

QString API_PLAYER::getName() const
{
    return name;
}

int API_PLAYER::getAge() const
{
    return age;
}

int API_PLAYER::getFN() const
{
    return FN;
}

int API_PLAYER::getSN() const
{
    return SN;
}

int API_PLAYER::getFP() const
{
    return FP;
}

int API_PLAYER::getSP() const
{
    return SP;
}

int API_PLAYER::getTW() const
{
    return TW;
}

int API_PLAYER::getClubId() const
{
    return club_id;
}

float API_PLAYER::getSkill() const
{
    return skill;
}

QString API_PLAYER::getStrSkill() const
{
    QString s;
    s.setNum(getSkill());
    return s;
}

int API_PLAYER::getTmBD() const
{
    return Tm_Birthday;
}

int API_PLAYER::getTmContrExp() const
{
    return Tm_ContractExp;
}

void API_PLAYER::setSkill(float val)
{
    skill = val;
}
