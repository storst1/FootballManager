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
    PLAYER(int id, QString name, int TW, int FN, int SN, int FP, int SP, QString height, int age, int club);
    ~PLAYER() = default;

    void setClubId(int id);

    int getId() const;
    QString getHeight() const;
    QString getName() const;
    int getAge() const;
    int getFN() const;
    int getSN() const;
    int getFP() const;
    int getSP() const;
    int getTW() const;
    int getClubId() const;
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
    int club_id;
};

#endif // PLAYER_H
