#pragma once
#ifndef CLUB_H
#define CLUB_H

#include "player.h"

#include <QString>
#include <QList>

class CLUB
{
public:
    CLUB();
    CLUB(int id);
    CLUB(int id, QString name);
    CLUB(int id, QString name, QString league_id);
    ~CLUB();

    void setLeagueId(QString leagueId);
    void setName(QString club_name);
    int getId() const;
    QString getStrId() const;
    QString getName() const;
    QString getLeagueId() const;
private:
    int id;
    QString name;
    QString league_id;
};

#endif // CLUB_H
