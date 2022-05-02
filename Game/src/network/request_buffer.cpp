#include "network/request_buffer.h"

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

bool REQUEST_BUFFER::isErrorMsg()
{
    static const QString errMsg1 = "You have exceeded the MONTHLY quota for Requests on your current plan, BASIC. "
                           "Upgrade your plan at https://rapidapi.com/apidojo/api/transfermarket";
    static const QString errMsg2 = "server replied: Too Many Requests";
    if(getBufferRef().contains(errMsg1) || getBufferRef().contains(errMsg2)){
        return true;
    }
    return false;
}

void REQUEST_BUFFER::operator=(const QString &str)
{
    this->buffer = str;
}

QChar REQUEST_BUFFER::operator[](int idx)
{
    if(idx < 0 || idx > buffer.size() - 1){
        //Exception: index id out of buffer's range
        return ' ';
    }
    return buffer[idx];
}

void REQUEST_BUFFER::NormalizeValue(QString &str)
{
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
    s.replace("\u00fc", "u");
    s.replace("\u00e3", "a");
    s.replace("\u00e7", "c");
    s.replace("\u00fa", "u");
    s.replace("\u00e4", "a");
}
