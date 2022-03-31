#ifndef FEDERATION_H
#define FEDERATION_H

#include "game/data/data_defs.h"

class FEDERATION
{
public:
    FEDERATION();
    FEDERATION(int _id, QString _name, int _countryId, QList<LEAGUE*> leaguesList);
    FEDERATION(int _id, QString _name, int _countryId);
    ~FEDERATION();

    int getId() const;
    QString getName() const;
    QList<LEAGUE*> getLeagues();

    void setLeagues(QList<LEAGUE*> leaguesList);
private:
    int fedId;
    int countryId;
    QString name;

    QList<LEAGUE*> leagues;
    CUP* natCup;

    NATIONAL_TEAM* nationalTeam;
};

#endif // FEDERATION_H
