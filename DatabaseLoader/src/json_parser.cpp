#include "json_parser.h"

JSON_PARSER::JSON_PARSER()
{

}

void JSON_PARSER::setJsonProperties(QByteArray jsonArr)
{
    jsonData = jsonArr;
    jsonDoc = QJsonDocument::fromJson(jsonData);
    mainObj = jsonDoc.object();
}
