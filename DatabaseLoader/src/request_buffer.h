#pragma once
#ifndef REQUEST_BUFFER_H
#define REQUEST_BUFFER_H

#include <QString>
#include <QList>

class REQUEST_BUFFER
{
public:
    REQUEST_BUFFER();
    ~REQUEST_BUFFER() = default;

    QString getBuffer();
    QString &getBufferRef();
    void setBuffer(const QString& str);
    QString GetValueFromRequestBuffer(const int beginingIdx);
    QList<QString> GetAllValuesFromRequestBuffer(const QList<int>& idxs, const int strLength);
    int indexOf(const QString& str);
    QList<int> indexOfAll(const QString& str);

    void operator=(const QString& str);
    QChar operator[](int idx);
private:
    QString buffer;
};

#endif // REQUEST_BUFFER_H
