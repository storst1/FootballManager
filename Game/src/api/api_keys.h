#ifndef API_KEYS_H
#define API_KEYS_H

#include "database/database_api_keys.h"

#include <QString>
#include <QVector>

class API_KEYS
{
public:
    API_KEYS(const QString& ApiDbPath);
    API_KEYS(QVector<QString> keys);

    const QString cur() const;
    QString next();
private:
    QVector<QString> keys;
    int curKey = -1;
};

#endif // API_KEYS_H
