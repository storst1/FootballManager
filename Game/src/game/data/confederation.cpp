#include "game/data/confederation.h"
#include "game/data/federation.h"

CONFEDERATION::CONFEDERATION()
{

}

CONFEDERATION::~CONFEDERATION()
{
    qDeleteAll(fedList);
}
