#include "calendar.h"

CALENDAR::CALENDAR(QList<TEAM *> &allTeams) : allTeams(allTeams)
{

}

CALENDAR::CALENDAR(QList<TEAM *> &allTeams, QList<int> &startingStage) : allTeams(allTeams), teamStartingStage(startingStage)
{

}

CALENDAR::CALENDAR(QList<QPair<TEAM *, int> > &infoList)
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

void CALENDAR::SetTeams(QList<TEAM *> &teams, QList<int> &&startingStage)
{
    allTeams = teams;
    teamStartingStage = startingStage;
}
