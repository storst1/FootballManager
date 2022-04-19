#include "game/data/player.h"
#include "game/data/player_position.h"
#include "game/data/team.h"
#include "game/data/federation.h"

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

bool PLAYER::CompTwoPlayersByPos(const PLAYER *p1, const PLAYER *p2)
{
    if(p1->getPos()->getFP() == p2->getPos()->getFP()){
        return p1->getSkill() > p2->getSkill();
    }
    return p1->getPos()->getFP() < p2->getPos()->getFP();
}

bool PLAYER::CompTwoPlayersByName(const PLAYER *p1, const PLAYER *p2)
{
    if(p1->getSkill() == p2->getSkill()){
        return CompTwoPlayersByPos(p1, p2);
    }
    return p1->getName() < p2->getName();
}

bool PLAYER::CompTwoPlayersByAge(const PLAYER *p1, const PLAYER *p2)
{
    if(p1->getSkill() == p2->getSkill()){
        return CompTwoPlayersByPos(p1, p2);
    }
    return p1->getAge() < p2->getAge();
}

bool PLAYER::CompTwoPlayersByTV(const PLAYER *p1, const PLAYER *p2)
{
    if(p1->getSkill() == p2->getSkill()){
        return CompTwoPlayersByPos(p1, p2);
    }
    return p1->getTV() < p2->getTV();
}

bool PLAYER::CompTwoPlayersBySkill(const PLAYER *p1, const PLAYER *p2)
{
    if(p1->getSkill() == p2->getSkill()){
        return CompTwoPlayersByPos(p1, p2);
    }
    return p1->getSkill() < p2->getSkill();
}

void PLAYER::addOneYearToAge()
{
    ++age;
}
