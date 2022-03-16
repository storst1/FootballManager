#pragma once
#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QString>
#include <QList>

class JSON_PARSER
{
public:
    JSON_PARSER();
    ~JSON_PARSER() = default;
protected:
    void setJsonProperties(QByteArray jsonArr);
protected:
    QByteArray jsonData;
    QJsonDocument jsonDoc;
    QJsonObject mainObj;
};

#endif // JSON_PARSER_H
