#include "database_api_keys.h"

DATABASE_API_KEYS::DATABASE_API_KEYS(const QString &dbPath, const QString &dbConnectionName)
    : DATABASE(dbPath, dbConnectionName)
{

}

QList<QString> DATABASE_API_KEYS::GetAllKeys()
{
    QSqlQuery query(*db);
    query.exec("SELECT key FROM keys;");
    DATABASE::PrintSqlExecInfoIfErr(query);
    QList<QString> keyList;
    while(query.next()){
        keyList.push_back(query.value(0).toString());
    }
    return keyList;
}
