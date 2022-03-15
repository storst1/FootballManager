#include "request_buffer.h"

REQUEST_BUFFER::REQUEST_BUFFER()
{
    buffer = "";
}

QString REQUEST_BUFFER::getBuffer() const
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

void REQUEST_BUFFER::NormalizeValue(QString &str)
{
    /*
    for(int i = 0; i < str.length(); ++i){
        if(QString(str[i]) == "'"){
            str.erase(std::next(str.cbegin(), i), std::next(str.cbegin(), i + 1));
            --i;
        }
    }
    */
    //qDebug() << str;
    ReplaceAllNonEnglishSymbols(str);
    //qDebug() << str;
}

QString REQUEST_BUFFER::NormalizeAndCopyValue(QString str)
{
    ReplaceAllNonEnglishSymbols(str);
    return str;
}

void REQUEST_BUFFER::NormalizeValues(QList<QString> &str_list)
{
    for(int i = 0; i < str_list.size(); ++i){
        str_list[i] = NormalizeAndCopyValue(str_list[i]);
    }
}

void REQUEST_BUFFER::ReplaceAllNonEnglishSymbols(QString &s)
{
    s.replace("\\u00c9", "E");
    s.replace("\\u00e9", "e");
    s.replace("\\u00e1", "a");
    s.replace("\\u00ee", "i");
    s.replace("\\u00ed", "i");
    s.replace("\\u00df", "s");
    s.replace("\\u00fc", "u");
    s.replace("\\u00f6", "o");
    s.replace("\\u00f3", "o");
}
