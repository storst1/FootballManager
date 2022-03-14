#include "request_buffer.h"
#include <QtDebug>

REQUEST_BUFFER::REQUEST_BUFFER()
{
    buffer = "";
}

QString REQUEST_BUFFER::getBuffer()
{
    return buffer;
}

QString &REQUEST_BUFFER::getBufferRef()
{
    return buffer;
}

void REQUEST_BUFFER::setBuffer(const QString &str)
{
    buffer = str;
}

QString REQUEST_BUFFER::GetValueFromRequestBuffer(const int beginingIdx)
{
    int i = beginingIdx;
    QString value;
    while(buffer[i] != '\"'){
        value += buffer[i];
        ++i;
    }
    return value;
}

QList<QString> REQUEST_BUFFER::GetAllValuesFromRequestBuffer(const QList<int> &idxs, const int strLength)
{
    QList<QString> retList;
    for(auto aidx : idxs){
        retList.push_back(GetValueFromRequestBuffer(aidx + strLength));
    }
    return retList;
}

int REQUEST_BUFFER::indexOf(const QString &str)
{
    return buffer.indexOf(str);
}

QList<int> REQUEST_BUFFER::indexOfAll(const QString &str)
{
    QList<int> idxs;
    int startingElem = 0;
    while(int cur = buffer.indexOf(str, startingElem)){
        if(cur < 0){
            break;
        }
        idxs.push_back(cur);
        startingElem = str.length() + cur + 1;
    }
    qDebug() << idxs;
    return idxs;
}

void REQUEST_BUFFER::operator=(const QString &str)
{
    this->buffer = str;
}

QChar REQUEST_BUFFER::operator[](int idx)
{
    return buffer[idx];
}
