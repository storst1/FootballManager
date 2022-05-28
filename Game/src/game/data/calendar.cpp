#include "calendar.h"

CALENDAR::CALENDAR(QVector<TEAM *> &allTeams) : allTeams(allTeams)
{

}

CALENDAR::CALENDAR(QVector<TEAM *> &allTeams, QVector<int> &startingStage) : allTeams(allTeams), teamStartingStage(startingStage)
{

}

CALENDAR::CALENDAR(QVector<QPair<TEAM *, int> > &infoList)
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
