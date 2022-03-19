#include "confederation.h"
#include "federation.h"

CONFEDERATION::CONFEDERATION()
{

}

CONFEDERATION::~CONFEDERATION()
{
    qDeleteAll(fedList);
}
