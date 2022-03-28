#include "player.h"
#include "player_position.h"
#include "team.h"
#include "federation.h"

PLAYER::PLAYER()
{

}

PLAYER::~PLAYER()
{
    delete pos;
}

int PLAYER::getId(){
    return id;
}

QString PLAYER::getName(){
    return name;
}

int8_t PLAYER::getAge(){
    return age;
}

float PLAYER::getSkill(){
    return skill;
}

FEDERATION* PLAYER::getFF(){
    return FF;
}

FEDERATION* PLAYER::getSF(){
    return SF;
}

PLAYER_POSITION* PLAYER::getPos(){
    return pos;
}

CLUB* PLAYER::getClub(){
    return club;
}
