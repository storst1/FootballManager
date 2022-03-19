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
