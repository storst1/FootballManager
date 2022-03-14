#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <json_parser_player.h>

#include <QString>

class PLAYER
{
public:
    PLAYER();
    PLAYER(int id, QString name, int TW, int FNid, int SNid, QString height);
    PLAYER(JSON_PARSER_PLAYER playerInfo);
    ~PLAYER() = default;
private:
    int id;
    QString name;
    int TW;
    int FN; //first nationality id
    int SN; //second nationionality id
    int FP;
    int SP;
    QString height;
    int age;
};

#endif // PLAYER_H
