#include "league_calendar.h"

void LEAGUE_CALENDAR::Generate(int start_year)
{
    int tours = (allTeams.size() - 1) * 2;
    //DATE startDate(QDateTime(QDate(start_year, ));
}

void LEAGUE_CALENDAR::Clear()
{
    calendar.clear();
}

QVector<SCHEDULED_MATCH *> LEAGUE_CALENDAR::GetTour(int id) const
{

}

QVector<SCHEDULED_MATCH *> LEAGUE_CALENDAR::GetTour(const QString &id) const
{

}

QString LEAGUE_CALENDAR::GetTourName(int id) const
{

}
