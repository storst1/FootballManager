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

    void setNations(QVector<FEDERATION *> nationsList);
    void setSecondNations(QVector<FEDERATION *> secondNationsList);
    void setName(QString _name);
    void setTeam(QString _team);
    void setLeagues(QVector<LEAGUE *> _leagues);
    void setMinAge(int min);
    void setMaxAge(int max);
    void setAgeBorders(int min, int max);
    void setPos(QVector<int> _positions);
    void setSecondPos(QVector<int> _positions);
    void setMinTV(int min);
    void setMaxTV(int max);
    void setTVBorders(int min, int max);
    void setMinSkill(int min);
    void setMaxSkill(int max);
    void setSkillBorders(int min, int max);

    QVector<FEDERATION *>& getNations();
    QVector<FEDERATION *>& getSecondNations();
    QString& getName();
    QString& getTeam();
    QVector<LEAGUE*>& getLeagues();
    int getMinAge() const;
    int getMaxAge() const;
    QVector<int>& getPositions();
    QVector<int>& getSecondPositions();
    int getMinTV() const;
    int getMaxTV() const;
    int getMinSkill() const;
    int getMaxSkill() const;
private:
    QVector<FEDERATION *> nations = {};
    QVector<FEDERATION *> secondNations = {};
    QString name = "";
    QString team = "";
    QVector<LEAGUE *> leagues = {};
    int minAge = 0;
    int maxAge = MAX_PLAYER_AGE;
    QVector<int> positions = {};
    QVector<int> secondPositions = {};
    int minTV = 0;
    int maxTV = MAX_PLAYER_TV;
    int minSkill = 0;
    int maxSkill = MAX_PLAYER_SKILL;
};

#endif // PLAYER_SEARCH_FILTER_H
