#include "federation.h"
#include "league.h"
#include "team.h"
#include "cup.h"

FEDERATION::FEDERATION()
{

}

FEDERATION::~FEDERATION()
{
    qDeleteAll(leagues);
    delete nationalTeam;
}
