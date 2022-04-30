#ifndef PLAYER_H
#define PLAYER_H

#include "game/data/data_defs.h"
#include "game/time/date.h"

#include <QRandomGenerator>

class PLAYER
{
public:
    PLAYER();
    PLAYER(int id,
           QString name,
           int TV,
           int age,
           float skill,
           FEDERATION* FF,
           FEDERATION* SF,
           PLAYER_POSITION* pos,
           QString height,
           DATE birthday,
           DATE contractExp
           );
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
    static bool CompTwoPlayersByPos(const PLAYER* p1, const PLAYER* p2);
    static bool CompTwoPlayersByName(const PLAYER* p1, const PLAYER* p2);
    static bool CompTwoPlayersByAge(const PLAYER* p1, const PLAYER* p2);
    static bool CompTwoPlayersByTV(const PLAYER* p1, const PLAYER* p2);
    static bool CompTwoPlayersBySkill(const PLAYER* p1, const PLAYER* p2);
    static bool CompTwoPlayersByPosReversed(const PLAYER* p1, const PLAYER* p2);
    static bool CompTwoPlayersByNameReversed(const PLAYER* p1, const PLAYER* p2);
    static bool CompTwoPlayersByAgeReversed(const PLAYER* p1, const PLAYER* p2);
    static bool CompTwoPlayersByTVReversed(const PLAYER* p1, const PLAYER* p2);
    static bool CompTwoPlayersBySkillReversed(const PLAYER* p1, const PLAYER* p2);

    static bool NormalizeTV(int &TV);
    static bool NormalizeAgeAndBirthday(int& age, int &rawBirthday);
    static void NormalizeHeight(QString& height);

    void addOneYearToAge();
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
    DATE birthday;
    DATE contractExp;
};

#endif // PLAYER_H
