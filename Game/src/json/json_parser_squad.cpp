#include "json/json_parser_squad.h"

JSON_PARSER_SQUAD::JSON_PARSER_SQUAD()
{

}

JSON_PARSER_SQUAD::JSON_PARSER_SQUAD(QString str)
{
    setJsonProperties(str.toUtf8());
    squadObjArr = mainObj.value("squad").toArray();
    for(int i = 0; i < squadObjArr.size(); ++i){
        playerObjs.push_back(squadObjArr[i].toObject());
    }
    InitPlayersInfoWithVals();
}

QVector<JSON_PARSER_PLAYER> JSON_PARSER_SQUAD::getPlayersParsers() const
{
    return playersInfo;
}

void JSON_PARSER_SQUAD::InitPlayersInfoWithVals()
{
    for(const auto &o : playerObjs){
        playersInfo.push_back(JSON_PARSER_PLAYER(o));
    }
}
