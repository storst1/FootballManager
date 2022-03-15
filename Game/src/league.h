#pragma once
#ifndef LEAGUE_H
#define LEAGUE_H

#include "club.h"

#include <QList>

class LEAGUE
{
public:
    LEAGUE();
    LEAGUE(QString id, int fed_id);
    LEAGUE(QString id, QString name, int federation);
    ~LEAGUE();

    void setName(QString& league_name);
    void setName(QString league_name);
    //void setClubs(QList<CLUB*>& clubs_list);
    QString getId() const;
    QString getName() const;
    int getFed() const;
    QString getStrFed() const;
private:
    QString id;
    QString name;
    int federation;
    //QList<CLUB*> clubs;
};

#endif // LEAGUE_H