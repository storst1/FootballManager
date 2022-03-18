#include "team.h"

TEAM::TEAM()
{

}

TEAM::~TEAM()
{
    qDeleteAll(players);
    delete coach;
}
