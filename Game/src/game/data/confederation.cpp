#include "confederation.h"

CONFEDERATION::CONFEDERATION()
{

}

CONFEDERATION::~CONFEDERATION()
{
    qDeleteAll(fedList);
}
