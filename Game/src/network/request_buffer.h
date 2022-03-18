#pragma once
#ifndef REQUEST_BUFFER_H
#define REQUEST_BUFFER_H

#include <QString>
#include <QList>
#include <QtDebug>

class REQUEST_BUFFER
{
public:
    REQUEST_BUFFER();
    ~REQUEST_BUFFER() = default;

    QString getBuffer() const;
    QString &getBufferRef();
    void setBuffer(const QString& str);
    QString GetValueFromRequestBuffer(const int beginingIdx);
    QList<QString> GetAllValuesFromRequestBuffer(const QList<int>& idxs, const int strLength);
    int indexOf(const QString& str);
    QList<int> indexOfAll(const QString& str);
    bool isErrorMsg();

    void operator=(const QString& str);
    QChar operator[](int idx);

    static void NormalizeValue(QString& str);
    static QString NormalizeAndCopyValue(QString str);
    static void NormalizeValues(QList<QString>& str_list);
    static void ReplaceAllNonEnglishSymbols(QString& s);
private:
    QString buffer;
};

#endif // REQUEST_BUFFER_H
