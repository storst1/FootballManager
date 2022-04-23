#ifndef JSON_PARSER_PLAYER_H
#define JSON_PARSER_PLAYER_H

#include "json_parser.h"

class JSON_PARSER_PLAYER : public JSON_PARSER
{
public:
    JSON_PARSER_PLAYER();
    JSON_PARSER_PLAYER(QString rawStr);
    JSON_PARSER_PLAYER(QJsonObject playerObj);
    ~JSON_PARSER_PLAYER() = default;

    int getId() const;
    QString getHeight() const;
    QString getName() const;
    int getAge() const;
    int getFN() const;
    int getSN() const;
    int getFP() const;
    int getSP() const;
    int getTW() const;
    int getBirthday_TmType() const;
    int getContractExp_TmType() const;
private:
    void BindJsonValues(QJsonObject playerObj);
private:
    QJsonValue height;
    QJsonValue id;
    QJsonValue name;
    QJsonValue age;

    QJsonArray nationalities;
    QJsonValue FNid;
    QJsonValue SNid;

    QJsonObject positions;
    QJsonObject FP;
    QJsonObject SP;
    QJsonValue FPid;
    QJsonValue SPid;

    QJsonObject TWobj;
    QJsonValue TW;

    QJsonValue birthday;
    QJsonValue contractExpDate;
};

#endif // JSON_PARSER_PLAYER_H
