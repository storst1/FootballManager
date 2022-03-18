#ifndef API_KEYS_H
#define API_KEYS_H

#include <QString>
#include <QList>

class API_KEYS
{
public:
    API_KEYS();
    API_KEYS(QList<QString> keys);

private:
    QList<QString> keys;
    int curKey = -1;
};

#endif // API_KEYS_H
