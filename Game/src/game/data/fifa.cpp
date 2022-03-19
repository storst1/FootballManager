#include "fifa.h"
#include "confederation.h"
#include "federation.h"

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
