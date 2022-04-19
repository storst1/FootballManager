#include "game/data/table.h"

TABLE::TABLE()
{

}

TABLE::~TABLE()
{
    qDeleteAll(standings);
}
