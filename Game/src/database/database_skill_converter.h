#ifndef DATABASE_SKILL_CONVERTER_H
#define DATABASE_SKILL_CONVERTER_H

#include "database/database.h"
#include "game/data/player.h"
#include "game/data/player_position.h"

class DATABASE_SKILL_CONVERTER : public DATABASE
{
public:
    DATABASE_SKILL_CONVERTER(const QString &dbPath, const QString& connectionName, int config);
    ~DATABASE_SKILL_CONVERTER() = default;

    float CountPlayerSkill(API_PLAYER* player);
    float CountPlayerSkill(PLAYER* player);
    float CountPlayerSkill(int TV, int age, int FP);
    void MakeBackup(const QString& backupDbName);
private:
    void ReadVariables(int config);
    void AssignTWConv(QList<QString>& list);
    void AssignAgeConv(QList<QString>& list, int AgeSP);
    void AssignPosConv(QList<QString>& list);
    //skill counting related methods
    float GetBaseByTW(int TW) const;
    float GetAgeCoef(int age) const;
    float GetPosCoef(int pos) const;
private:
    QList<int> TWconv;
    int lastZeroInTWconv;

    QList<float> AgeCoefMap;
    QList<float> PosCoefMap;
};

#endif // DATABASE_SKILL_CONVERTER_H
