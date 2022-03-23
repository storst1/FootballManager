#ifndef CLUB_H
#define CLUB_H

#include "json/json_parser_club.h"

#include <QString>
#include <QList>

class API_CLUB
{
public:
    API_CLUB();
    API_CLUB(int id);
    API_CLUB(int id, QString name);
    API_CLUB(int id, QString name, QString league_id);
    API_CLUB(int id, QString name, QString league_id, QString sd_name, int sd_cap, int totalTV);
    ~API_CLUB();

    void setLeagueId(QString leagueId);
    void setName(QString club_name);
    void insertAdditionalInfoFromJson(JSON_PARSER_CLUB clubAddInfo);
    void addTV(int playerTV);

    void countBudget();

    int getId() const;
    QString getStrId() const;
    QString getName() const;
    QString getLeagueId() const;
    QString getStadName() const;
    int getStadCapacity() const;
    int getTV() const;
private:
    int id;
    QString name;
    QString league_id;
    QString stadName;
    int stadCapacity;
    int totalTV = 0;
    int prestige;
    int budget;
};

#endif // CLUB_H
