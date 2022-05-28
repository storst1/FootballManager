#ifndef COUNTRY_MAP_H
#define COUNTRY_MAP_H

#include <QMap>
#include <QString>
#include <QVector>
#include <QPair>

class COUNTRY_MAP
{
public:
    COUNTRY_MAP();
    COUNTRY_MAP(QVector<QPair<int, QString>>& list);
    ~COUNTRY_MAP() = default;

    void fillMaps(QVector<QPair<int, QString>>& list);
    QString getById(const int id) const;
    int getByName(const QString name) const;
    bool isEmpty() const;
private:
    QMap<int, QString> intToStr;
    QMap<QString, int> strToInt;
};

#endif // COUNTRY_MAP_H
