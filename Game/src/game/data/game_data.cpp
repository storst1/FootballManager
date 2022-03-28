#include "game_data.h"
#include "fifa.h"
#include "federation.h"
#include "league.h"
#include "team.h"
#include "player.h"

GAME_DATA::GAME_DATA()
{

}

GAME_DATA::~GAME_DATA()
{
    delete fifa;
    qDeleteAll(federations);
    qDeleteAll(leagues);
    qDeleteAll(clubs);
    qDeleteAll(players);
}
