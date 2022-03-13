#include "request_buffer.h"

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

int REQUEST_BUFFER::indexOf(const QString &str)
{
    return buffer.indexOf(str);
}

void REQUEST_BUFFER::operator=(const QString &str)
{
    this->buffer = str;
}

QChar REQUEST_BUFFER::operator[](int idx)
{
    return buffer[idx];
}
