#include "json_parser_club.h"

JSON_PARSER_CLUB::JSON_PARSER_CLUB()
{

}

JSON_PARSER_CLUB::JSON_PARSER_CLUB(QString str)
{
    setJsonProperties(str.toUtf8());
    BindJsonValues(mainObj);
}

void JSON_PARSER_CLUB::BindJsonValues(QJsonObject obj)
{
    int i = 0;
}
