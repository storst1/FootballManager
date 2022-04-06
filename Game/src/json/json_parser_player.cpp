#include "json_parser_player.h"

JSON_PARSER_PLAYER::JSON_PARSER_PLAYER()
{

}

JSON_PARSER_PLAYER::JSON_PARSER_PLAYER(QString rawStr)
{
    //Unused function
    setJsonProperties(rawStr.toUtf8()); //QString to QByteArray for JSON parse
    BindJsonValues(mainObj);
}

JSON_PARSER_PLAYER::JSON_PARSER_PLAYER(QJsonObject playerObj)
{
    BindJsonValues(playerObj);
}

int JSON_PARSER_PLAYER::getId() const
{
    return id.toString().toInt();
}

QString JSON_PARSER_PLAYER::getHeight() const
{
    return height.toString();
}

QString JSON_PARSER_PLAYER::getName() const
{
    return name.toString();
}

int JSON_PARSER_PLAYER::getAge() const
{
    return age.toInt();
}

int JSON_PARSER_PLAYER::getFN() const
{
    return FNid.toInt();
}

int JSON_PARSER_PLAYER::getSN() const
{
    return SNid.toInt();
}

int JSON_PARSER_PLAYER::getFP() const
{
    return FPid.toString().toInt();
}

int JSON_PARSER_PLAYER::getSP() const
{
    return SPid.toString().toInt();
}

int JSON_PARSER_PLAYER::getTW() const
{
    return TW.toInt();
}

int JSON_PARSER_PLAYER::getTBirthday_TmType() const
{
    return birthday.toInt();
}

int JSON_PARSER_PLAYER::getContractExp_TmType() const
{
    return contractExpDate.toInt();
}

void JSON_PARSER_PLAYER::BindJsonValues(QJsonObject playerObj)
{
    height = playerObj.value("height");
    id = playerObj.value("id");
    name = playerObj.value("name");
    age = playerObj.value("age");

    nationalities = playerObj.value("nationalities").toArray();
    FNid = nationalities[0].toObject().value("id");
    SNid = nationalities[1].toObject().value("id");

    positions = playerObj.value("positions").toObject();
    FP = positions.value("first").toObject();
    FPid = FP.value("id");
    SP = positions.value("second").toObject();
    SPid = SP.value("id");

    TWobj = playerObj.value("marketValue").toObject();
    TW = TWobj.value("value");

    birthday = playerObj.value("dateOfBirth");
    contractExpDate = playerObj.value("contractUntil");
}
