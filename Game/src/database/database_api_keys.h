#ifndef DATABASE_API_KEYS_H
#define DATABASE_API_KEYS_H

#include "database.h"

class DATABASE_API_KEYS : public DATABASE
{
public:
    DATABASE_API_KEYS(const QString& dbPath, const QString& dbConnectionName);
    ~DATABASE_API_KEYS() = default;

    QList<QString> GetAllKeys();
};

#endif // DATABASE_API_KEYS_H
