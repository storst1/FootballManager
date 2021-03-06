#ifndef FEDERATION_H
#define FEDERATION_H

#include "game/data/data_defs.h"

class FEDERATION
{
public:
    FEDERATION();
    FEDERATION(int _id, QString _name, int _countryId, QVector<LEAGUE*> leaguesList);
    FEDERATION(int _id, QString _name, int _countryId);
    ~FEDERATION();

    int getId() const;
    QString getName() const;
    QVector<LEAGUE*> getLeagues();
    QPixmap* getFlag() const;

    void setLeagues(QVector<LEAGUE*> leaguesList);
    void setFlag(QPixmap* flag);

    static bool CompTwoFedsByName(const FEDERATION* f1, const FEDERATION* f2);
private:
    int fedId;
    int countryId;
    QString name;
    QPixmap* flagPixmap = nullptr;

    QVector<LEAGUE*> leagues;
    CUP* natCup;

    NATIONAL_TEAM* nationalTeam;
};

#endif // FEDERATION_H
