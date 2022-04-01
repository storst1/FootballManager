#include "player.h"
#include "player_position.h"
#include "team.h"
#include "federation.h"

PLAYER::PLAYER()
{

}

PLAYER::PLAYER(int id, QString name, int TV, int age, float skill, FEDERATION *FF, FEDERATION *SF,
               PLAYER_POSITION* pos, QString height) :
    id(id), name(name), TV(TV), age(age), skill(skill), FF(FF), SF(SF), pos(pos), height(height)
{

}

PLAYER::~PLAYER()
{
    delete pos;
}

int PLAYER::getId() const{
    return id;
}

QString PLAYER::getName() const{
    return name;
}

int8_t PLAYER::getAge() const{
    return age;
}

float PLAYER::getSkill() const{
    return skill;
}

FEDERATION* PLAYER::getFF() const{
    return FF;
}

FEDERATION* PLAYER::getSF() const{
    return SF;
}

PLAYER_POSITION* PLAYER::getPos() const{
    return pos;
}

CLUB* PLAYER::getClub() const{
    return club;
}

int PLAYER::getTV() const
{
    return TV;
}

void PLAYER::setClub(CLUB *clubPtr)
{
    club = clubPtr;
}
