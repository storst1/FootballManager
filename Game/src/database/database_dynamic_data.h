#ifndef DATABASE_DYNAMIC_DATA_H
#define DATABASE_DYNAMIC_DATA_H

#include "database.h"

class DATABASE_DYNAMIC_DATA : public DATABASE
{
public:
    DATABASE_DYNAMIC_DATA(const QString& dbPath, const QString& connectionName);
    ~DATABASE_DYNAMIC_DATA() = default;

    void LoadAllDataFromAPILists();
};

#endif // DATABASE_DYNAMIC_DATA_H
