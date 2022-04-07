#include "user.h"
#include "game/data/team.h"

USER::USER()
{

}

CLUB *USER::getClub() const
{
    return club;
}

void USER::setClub(CLUB *curClub)
{
    club = curClub;
}
