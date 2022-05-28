#include "api/api_keys.h"

API_KEYS::API_KEYS(const QString &ApiDbPath)
{
    DATABASE_API_KEYS apiDb(ApiDbPath, "DB_API_KEYS");
    keys = apiDb.GetAllKeys();
    curKey = 0;
}

API_KEYS::API_KEYS(QVector<QString> keys) : keys(keys)
{
    curKey = 0;
}

const QString API_KEYS::cur() const
{
    if(keys.empty()){
        return "";
    }
    return keys[curKey];
}

QString API_KEYS::next()
{
    //Returns the next key in the list
    //If list is empty returns an empty string
    //If current key was the last one in the list, returns first element of the list
    if(keys.empty()){
        return "";
    }
    curKey = (curKey + 1) % keys.size();
    return keys[curKey];
}
