#ifndef API_LEAGUE_H
#define API_LEAGUE_H

#include "api_club.h"

#include <QList>

class API_LEAGUE
{
public:
    API_LEAGUE();
    API_LEAGUE(QString id, int fed_id);
    API_LEAGUE(QString id, QString name, int federation);
    ~API_LEAGUE();

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

#endif // API_LEAGUE_H
