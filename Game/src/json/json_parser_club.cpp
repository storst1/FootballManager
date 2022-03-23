#include "json_parser_club.h"

JSON_PARSER_CLUB::JSON_PARSER_CLUB()
{

}

JSON_PARSER_CLUB::JSON_PARSER_CLUB(QString str)
{
    setJsonProperties(str.toUtf8());
    BindJsonValues(mainObj);
}

QString JSON_PARSER_CLUB::getStadName() const
{
    return stadName.toString();
}

int JSON_PARSER_CLUB::getStadCapacity() const
{
    return stadCapacity.toInt();
}

void JSON_PARSER_CLUB::BindJsonValues(QJsonObject obj)
{
    QJsonObject stadObj = obj.value("stadium").toObject();
    stadName = stadObj.value("name");
    stadCapacity = stadObj.value("totalCapacity");
    qDebug() << stadName.toString() << " " << stadCapacity.toString();
}
