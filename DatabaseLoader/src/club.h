#pragma once
#ifndef CLUB_H
#define CLUB_H

#include <QString>

class CLUB
{
public:
    CLUB();
    CLUB(int id);
    CLUB(int id, QString name);
    ~CLUB() = default;

    void setName(QString club_name);
    int getId() const;
    QString getStrId() const;
    QString getName() const;
private:
    int id;
    QString name;
};

#endif // CLUB_H
