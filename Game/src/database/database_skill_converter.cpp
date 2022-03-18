#include "database_skill_converter.h"

DATABASE_SKILL_CONVERTER::DATABASE_SKILL_CONVERTER(const QString &dbPath, const QString& connectionName, int config)
    : DATABASE(dbPath, connectionName)
{
    if(config == -1){
        //Just set up the connection
        return;
    }
    TWconv.resize(100, 0);
    lastZeroInTWconv = 0;
    AgeCoefMap.resize(60);
    PosCoefMap.resize(16, 1.f);
    ReadVariables(config);
}

float DATABASE_SKILL_CONVERTER::CountPlayerSkill(API_PLAYER *player)
{
    return GetBaseByTW(player->getTW() * GetAgeCoef(player->getAge()) * GetPosCoef(player->getFP()));
}

void DATABASE_SKILL_CONVERTER::MakeBackup(const QString &backupDbPath)
{
    DATABASE_SKILL_CONVERTER backupDb(backupDbPath, "DB_SKILL_BACKUP", -1);
    //backupDb.db->setDatabaseName("");
    QSqlQuery   backupQuery(*backupDb.db);
    backupQuery.exec("CREATE TABLE 'rules' ("
                     "'config'	INTEGER UNIQUE,"
                     "'TW_conv'	TEXT,"
                     "'Age_coef_conv'	TEXT,"
                     "'Pos_coef_conv'	TEXT,"
                     "'Age_start_point'	INTEGER,"
                     "PRIMARY KEY('config' AUTOINCREMENT)"
                 ")");

    backupDb.DeleteTableInfo("rules");

    QSqlQuery query(*db);
    query.exec("ATTACH DATABASE '" + backupDbPath + "' AS backup;");
    query.exec("INSERT INTO backup.rules SELECT * FROM rules");
}

void DATABASE_SKILL_CONVERTER::ReadVariables(int config){
    QSqlQuery query(*db);
    //qDebug() << db->connectionName();
    query.exec("SELECT TW_conv, Age_coef_conv, Pos_coef_conv, Age_start_point FROM rules WHERE config = " + QString::number(config) + " LIMIT 1;");
    query.next();
    //qDebug() << "1: " << query.lastError().text();
    QString TWConvStr = query.value(0).toString();
    //qDebug() << "2: " << query.lastError().text();
    QString AgeConvStr = query.value(1).toString();
    QString PosConvStr = query.value(2).toString();
    int AgeSP = query.value(3).toInt();
    QList<QString> TWParsed = ParseStringBy(TWConvStr, '\n');
    AssignTWConv(TWParsed);
    QList<QString> AgeParsed = ParseStringBy(AgeConvStr, '\n');
    AssignAgeConv(AgeParsed, AgeSP);
    QList<QString> PosParsed = ParseStringBy(PosConvStr, '\n');
    AssignPosConv(PosParsed);

    /*
    qDebug() << TWconv;
    qDebug() << AgeCoefMap;
    qDebug() << PosCoefMap;
    */
}

void DATABASE_SKILL_CONVERTER::AssignTWConv(QList<QString> &list)
{
    int i = 0;
    for(; i < list.size(); ++i){
        list[i].replace(",", ".");
        TWconv[99 - i] = (int)(list[i].toFloat() * 1e6f);
    }
    lastZeroInTWconv = 99 - i;
}

void DATABASE_SKILL_CONVERTER::AssignAgeConv(QList<QString> &list, int AgeSP)
{
    std::reverse(list.begin(), list.end());
    int i = AgeSP;
    int j = 0;
    for(; i < std::min(AgeSP + list.size(), AgeCoefMap.size()); ++i, ++j){
        list[j].replace(",", ".");
        if(list[j].back() == '\r')
            list[j].erase(list[j].cend() - 1, list[j].cend());
        AgeCoefMap[i] = list[j].toFloat();
    }
    //Take care of idxs that are < AgeSp
    for(int m = AgeSP - 1; m > -1; --m){
        AgeCoefMap[m] = AgeCoefMap[AgeSP];
    }
    //Take care of idxs that are > AgeSp
    for(int x = i; x < AgeCoefMap.size(); ++x){
        AgeCoefMap[x] = AgeCoefMap[i - 1];
    }
}

void DATABASE_SKILL_CONVERTER::AssignPosConv(QList<QString> &list)
{
    for(int i = 0; i < std::min(list.size(), PosCoefMap.size()); ++i){
        list[i].replace(",", ".");
        PosCoefMap[i] = list[i].toFloat();
    }
}

float DATABASE_SKILL_CONVERTER::GetBaseByTW(int TW)
{
    int i = lastZeroInTWconv;
    while(TWconv[i] < TW && i < 100) ++i;
    return (float)i;
}

float DATABASE_SKILL_CONVERTER::GetAgeCoef(int age)
{
    return AgeCoefMap[age];
}

float DATABASE_SKILL_CONVERTER::GetPosCoef(int pos)
{
    return PosCoefMap[pos];
}
