#ifndef PLAYER_SEARCH_FILTER_H
#define PLAYER_SEARCH_FILTER_H

#include "game/data/federation.h"
#include "game/data/team.h"
#include "game/data/league.h"

#define MAX_PLAYER_AGE 100
#define MAX_PLAYER_TV 1000000000
#define MAX_PLAYER_SKILL 101

class PLAYER_SEARCH_FILTER
{
public:
    PLAYER_SEARCH_FILTER();
    ~PLAYER_SEARCH_FILTER() = default;

    void setNations(QList<FEDERATION *> nationsList);
    void setSecondNations(QList<FEDERATION *> secondNationsList);
    void setName(QString _name);
    void setTeam(QString _team);
    void setLeagues(QList<LEAGUE *> _leagues);
    void setMinAge(int min);
    void setMaxAge(int max);
    void setAgeBorders(int min, int max);
    void setPos(QList<int> _positions);
    void setSecondPos(QList<int> _positions);
    void setMinTV(int min);
    void setMaxTV(int max);
    void setTVBorders(int min, int max);
    void setMinSkill(int min);
    void setMaxSkill(int max);
    void setSkillBorders(int min, int max);

    QList<FEDERATION *>& getNations();
    QList<FEDERATION *>& getSecondNations();
    QString& getName();
    QString& getTeam();
    QList<LEAGUE*>& getLeagues();
    int getMinAge() const;
    int getMaxAge() const;
    QList<int>& getPositions();
    QList<int>& getSecondPositions();
    int getMinTV() const;
    int getMaxTV() const;
    int getMinSkill() const;
    int getMaxSkill() const;
private:
    QList<FEDERATION *> nations = {};
    QList<FEDERATION *> secondNations = {};
    QString name = "";
    QString team = "";
    QList<LEAGUE *> leagues = {};
    int minAge = 0;
    int maxAge = MAX_PLAYER_AGE;
    QList<int> positions = {};
    QList<int> secondPositions = {};
    int minTV = 0;
    int maxTV = MAX_PLAYER_TV;
    int minSkill = 0;
    int maxSkill = MAX_PLAYER_SKILL;
};

#endif // PLAYER_SEARCH_FILTER_H
