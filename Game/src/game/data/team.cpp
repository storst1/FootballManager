#include "team.h"
#include "coach.h"
#include "player.h"
#include "stadium.h"

TEAM::TEAM()
{

}

TEAM::~TEAM()
{
    qDeleteAll(players);
    delete coach;
}
