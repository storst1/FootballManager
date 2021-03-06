#ifndef JSON_PARSER_CLUB_H
#define JSON_PARSER_CLUB_H

#include "json_parser.h"

class JSON_PARSER_CLUB : public JSON_PARSER
{
public:
    JSON_PARSER_CLUB();
    JSON_PARSER_CLUB(QString str);
    ~JSON_PARSER_CLUB() = default;

    QString getStadName() const;
    int getStadCapacity() const;
private:
    void BindJsonValues(QJsonObject obj);
private:
    QJsonValue stadName;
    QJsonValue stadCapacity;
};

#endif // JSON_PARSER_CLUB_H
