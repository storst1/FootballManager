#include "federation.h"

FEDERATION::FEDERATION()
{

}

FEDERATION::~FEDERATION()
{
    qDeleteAll(leagues);
    delete nationalTeam;
}
