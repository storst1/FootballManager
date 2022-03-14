#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class PLAYER
{
public:
    PLAYER();
    PLAYER(int id, QString name, int TW, int FNid, int SNid, float height);
    ~PLAYER() = default;
private:
    int id;
    QString name;
    int TW;
    int FNid; //first nationality id
    int SNid; //second nationionality id
    float height;
};

#endif // PLAYER_H
