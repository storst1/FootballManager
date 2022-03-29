#ifndef FEDERATION_H
#define FEDERATION_H

#include "game/data/data_defs.h"

class FEDERATION
{
public:
    FEDERATION();
    FEDERATION(int _id, QString _name, int _countryId, QList<LEAGUE*> leaguesList);
    ~FEDERATION();

    int getId();
    QString getName();
    QList<LEAGUE*> getLeagues();
private:
    int fedId;
    int countryId;
    QString name;

    QList<LEAGUE*> leagues;
    CUP* natCup;

    NATIONAL_TEAM* nationalTeam;
};

#endif // FEDERATION_H
