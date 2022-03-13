#ifndef LEAGUE_H
#define LEAGUE_H

#include "club.h"

#include <QList>

class LEAGUE
{
public:
    LEAGUE();
    LEAGUE(QString id, int fed_id);
    LEAGUE(QString id, QString name, int federation, QList<CLUB*> clubs);

    void setName(QString& league_name);
    void setClubs(QList<CLUB*>& clubs_list);
private:
    QString id;
    QString name;
    int federation;
    QList<CLUB*> clubs;
};

#endif // LEAGUE_H
