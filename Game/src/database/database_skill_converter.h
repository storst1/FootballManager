#pragma once
#ifndef DATABASE_SKILL_CONVERTER_H
#define DATABASE_SKILL_CONVERTER_H

#include "database.h"

class DATABASE_SKILL_CONVERTER : public DATABASE
{
public:
    DATABASE_SKILL_CONVERTER(const QString &dbPath, const QString& connectionName, int config);
    ~DATABASE_SKILL_CONVERTER() = default;

    float CountPlayerSkill(API_PLAYER* player);
private:
    void ReadVariables(int config);
    void AssignTWConv(QList<QString>& list);
    void AssignAgeConv(QList<QString>& list, int AgeSP);
    void AssignPosConv(QList<QString>& list);
    //skill counting related methods
    float GetBaseByTW(int TW);
    float GetAgeCoef(int age);
    float GetPosCoef(int pos);
private:
    QList<int> TWconv;
    int lastZeroInTWconv;

    QList<float> AgeCoefMap;
    QList<float> PosCoefMap;
};

#endif // DATABASE_SKILL_CONVERTER_H
