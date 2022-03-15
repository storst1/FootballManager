#pragma once
#ifndef JSON_PARSER_SQUAD_H
#define JSON_PARSER_SQUAD_H

#include "json_parser.h"
#include "json_parser_player.h"

class JSON_PARSER_SQUAD : public JSON_PARSER
{
public:
    JSON_PARSER_SQUAD();
    JSON_PARSER_SQUAD(QString str);
    ~JSON_PARSER_SQUAD() = default;

    QList<JSON_PARSER_PLAYER> getPlayersParsers() const;
private:
    void InitPlayersInfoWithVals();
private:
    QJsonArray squadObjArr;
    QList<QJsonObject> playerObjs;
    QList<JSON_PARSER_PLAYER> playersInfo;
};

#endif // JSON_PARSER_SQUAD_H
