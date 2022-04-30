#include "game/data/player.h"
#include "game/data/player_position.h"
#include "game/data/team.h"
#include "game/data/federation.h"

PLAYER::PLAYER()
{

}

PLAYER::PLAYER(int id, QString name, int TV, int age, float skill, FEDERATION *FF, FEDERATION *SF,
               PLAYER_POSITION* pos, QString height, DATE birthday, DATE contractExp) :
    id(id), name(name), TV(TV), age(age), skill(skill), FF(FF), SF(SF), pos(pos), height(height),
    birthday(birthday), contractExp(contractExp)
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

bool PLAYER::NormalizeTV(int& TV)
{
    if(TV == 0){
        int i = QRandomGenerator::global()->bounded(0, 5);
        if(i == 0){
            TV = 1000;
        }
        else if(i == 1){
            TV = 2500;
        }
        else if(i == 2){
            TV = 5000;
        }
        else if(i == 3){
            TV = 7500;
        }
        else{ //i == 4
            TV = 10000;
        }
        return true;
    }
    return false;
}

bool PLAYER::NormalizeAgeAndBirthday(int &age, int& rawBirthday)
{
    if(age == 0 || rawBirthday == 0){
        rawBirthday = DATE::generateRandomRawDate();
        age = DATE::agesPassedSince(rawBirthday);
        return true;
    }
    return false;
}

void PLAYER::NormalizeHeight(QString &height)
{
    if(height == ""){
        int randHeight = QRandomGenerator::global()->bounded(157, 204);
        float floatHeight = randHeight / 100.f;
        height = QString::number(floatHeight);
        height.replace(".", ",");
    }
}

void PLAYER::addOneYearToAge()
{
    ++age;
}

bool PLAYER::CompTwoPlayersByPosReversed(const PLAYER *p1, const PLAYER *p2)
{
    if(p1->getPos()->getFP() == p2->getPos()->getFP()){
        return p1->getSkill() > p2->getSkill();
    }
    return p1->getPos()->getFP() > p2->getPos()->getFP();
}

bool PLAYER::CompTwoPlayersByNameReversed(const PLAYER *p1, const PLAYER *p2)
{
    if(p1->getSkill() == p2->getSkill()){
        return CompTwoPlayersByPos(p1, p2);
    }
    return p1->getName() > p2->getName();
}

bool PLAYER::CompTwoPlayersByAgeReversed(const PLAYER *p1, const PLAYER *p2)
{
    if(p1->getSkill() == p2->getSkill()){
        return CompTwoPlayersByPos(p1, p2);
    }
    return p1->getAge() > p2->getAge();
}

bool PLAYER::CompTwoPlayersByTVReversed(const PLAYER *p1, const PLAYER *p2)
{
    if(p1->getSkill() == p2->getSkill()){
        return CompTwoPlayersByPos(p1, p2);
    }
    return p1->getTV() > p2->getTV();
}

bool PLAYER::CompTwoPlayersBySkillReversed(const PLAYER *p1, const PLAYER *p2)
{
    if(p1->getSkill() == p2->getSkill()){
        return CompTwoPlayersByPos(p1, p2);
    }
    return p1->getSkill() > p2->getSkill();
}
