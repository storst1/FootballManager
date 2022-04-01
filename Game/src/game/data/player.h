#ifndef PLAYER_H
#define PLAYER_H

#include "game/data/data_defs.h"

class PLAYER
{
public:
    PLAYER();
    PLAYER(int id, QString name, int TV, int age, float skill, FEDERATION* FF, FEDERATION* SF, PLAYER_POSITION* pos, QString height);
    ~PLAYER();

    int getId() const;
    QString getName() const;
    int8_t getAge() const;
    float getSkill() const;
    FEDERATION* getFF() const;
    FEDERATION* getSF() const;
    PLAYER_POSITION* getPos() const;
    CLUB* getClub() const;
    int getTV() const;

    void setClub(CLUB* clubPtr);
private:
    int id;
    QString name;
    int TV;
    int8_t age;
    float skill;
    FEDERATION* FF;
    FEDERATION* SF;
    PLAYER_POSITION* pos;
    QString height;
    CLUB* club;
};

#endif // PLAYER_H
