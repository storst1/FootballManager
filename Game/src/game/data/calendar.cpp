#include "calendar.h"

CALENDAR::CALENDAR(QVector<TEAM *> &allTeams, COMPETITION *comp) : allTeams(allTeams), comp(comp)
{

}

CALENDAR::CALENDAR(QVector<TEAM *> &allTeams, QVector<int> &startingStage, COMPETITION *comp)
    : allTeams(allTeams), teamStartingStage(startingStage), comp(comp)
{

}

CALENDAR::CALENDAR(QVector<QPair<TEAM *, int> > &infoList, COMPETITION *comp) : comp(comp)
{
    for(const auto &l : infoList){
        allTeams.push_back(l.first);
        teamStartingStage.push_back(l.second);
    }
}

void CALENDAR::ClearTeams()
{
    allTeams.clear();
    teamStartingStage.clear();
}

void CALENDAR::SetTeams(QVector<TEAM *> &teams, QVector<int> &&startingStage)
{
    allTeams = teams;
    teamStartingStage = startingStage;
}

int CALENDAR::GetNextIdAndIncr()
{
    ++nextUniqueGameId;
    return nextUniqueGameId - 1;
}
