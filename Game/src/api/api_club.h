#ifndef CLUB_H
#define CLUB_H

#include "api_player.h"

#include <QString>
#include <QList>

class API_CLUB
{
public:
    API_CLUB();
    API_CLUB(int id);
    API_CLUB(int id, QString name);
    API_CLUB(int id, QString name, QString league_id);
    ~API_CLUB();

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
