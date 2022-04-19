#include "game/data/country_map.h"

COUNTRY_MAP::COUNTRY_MAP()
{

}

COUNTRY_MAP::COUNTRY_MAP(QList<QPair<int, QString> > &list)
{
    fillMaps(list);
}

void COUNTRY_MAP::fillMaps(QList<QPair<int, QString> > &list)
{
    for(const auto &p : list){
        intToStr.insert(p.first, p.second);
        strToInt.insert(p.second, p.first);
    }
}

QString COUNTRY_MAP::getById(const int id) const
{
    if(intToStr.find(id) == intToStr.end()){
        return "Undefined";
    }
    return intToStr[id];
}

int COUNTRY_MAP::getByName(const QString name) const
{
    if(strToInt.find(name) == strToInt.end()){
        return -1;
    }
    return strToInt[name];
}

bool COUNTRY_MAP::isEmpty() const
{
    return strToInt.isEmpty();
}
