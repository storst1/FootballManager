#include "game/data/fifa.h"
#include "game/data/confederation.h"
#include "game/data/federation.h"

FIFA::FIFA()
{

}

FIFA::~FIFA()
{
    delete CAF;
    delete CONCACAF;
    delete UEFA;
    delete AFC;
    delete OFC;
    delete CONMEBOL;
}
