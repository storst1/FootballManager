#ifndef API_PLAYER_H
#define API_PLAYER_H

#include "json/json_parser_player.h"

#include <QString>

class API_PLAYER
{
public:
    API_PLAYER();
    API_PLAYER(int id, QString name, int TW, int FNid, int SNid, QString height);
    API_PLAYER(JSON_PARSER_PLAYER playerInfo);
    API_PLAYER(int id, QString name, int TW, int FN, int SN, int FP, int SP, QString height, int age, int club);
    ~API_PLAYER() = default;

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

    float getSkill() const;
    QString getStrSkill() const;

    void setSkill(float val);
private:
    int id;
    QString name;
    int TW;
    int FN; //first nationality id
    int SN; //second nationionality id
    int FP; //first position id
    int SP; //second position id
    QString height;
    int age;
    int club_id;

    float skill = 0.f;
};

#endif // API_PLAYER_H
