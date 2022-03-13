#pragma once
#ifndef REQUEST_BUFFER_H
#define REQUEST_BUFFER_H

#include <QString>

class REQUEST_BUFFER
{
public:
    REQUEST_BUFFER();
    ~REQUEST_BUFFER() = default;

    QString getBuffer();
    QString &getBufferRef();
    void setBuffer(const QString& str);
    QString GetValueFromRequestBuffer(const int beginingIdx);
    int indexOf(const QString& str);

    void operator=(const QString& str);
    QChar operator[](int idx);
private:
    QString buffer;
};

#endif // REQUEST_BUFFER_H
