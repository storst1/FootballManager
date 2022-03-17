#include "table.h"

TABLE::TABLE()
{

}

TABLE::~TABLE()
{
    qDeleteAll(standings);
}
