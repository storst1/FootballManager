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
    ~CLUB();

    void setName(QString club_name);
    int getId() const;
    QString getStrId() const;
    QString getName() const;
    void setPlayers(QList<PLAYER*> playerList);
private:
    int id;
    QString name;
    QList<PLAYER*> players;
};

#endif // CLUB_H
