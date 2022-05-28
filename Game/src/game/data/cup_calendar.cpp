#include "cup_calendar.h"


CUP_CALENDAR::CUP_CALENDAR(QVector<TEAM *> &allTeams, COMPETITION* comp) : CALENDAR(allTeams, comp)
{

}

CUP_CALENDAR::CUP_CALENDAR(QVector<TEAM *> &allTeams, QVector<int> &startingStage, COMPETITION* comp) : CALENDAR(allTeams, comp)
{

}

CUP_CALENDAR::CUP_CALENDAR(QVector<QPair<TEAM *, int> > &infoList, COMPETITION* comp) : CALENDAR(allTeams, comp)
{

}

void CUP_CALENDAR::Generate(int start_year)
{

}

void CUP_CALENDAR::Clear()
{

}

QVector<SCHEDULED_MATCH *> CUP_CALENDAR::GetTour(int id) const
{

}

QVector<SCHEDULED_MATCH *> CUP_CALENDAR::GetTour(const QString &id) const
{

}

QString CUP_CALENDAR::GetTourName(int id) const
{

}

void CUP_CALENDAR::BindToursNames(QVector<QString> names)
{

}
