#include "fifa.h"

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
