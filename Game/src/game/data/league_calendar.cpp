#include "league_calendar.h"

LEAGUE_CALENDAR::LEAGUE_CALENDAR(QVector<TEAM *> &allTeams, COMPETITION* comp) : CALENDAR(allTeams, comp)
{

}

LEAGUE_CALENDAR::LEAGUE_CALENDAR(QVector<TEAM *> &allTeams, QVector<int> &startingStage, COMPETITION* comp)
    : CALENDAR(allTeams, startingStage, comp)
{

}

LEAGUE_CALENDAR::LEAGUE_CALENDAR(QVector<QPair<TEAM *, int> > &infoList, COMPETITION* comp) : CALENDAR(infoList, comp)
{

}

void LEAGUE_CALENDAR::Generate(int start_year)
{
    int tours = (allTeams.size() - 1) * 2;
    //Shuffle teamList
    std::random_device rd;
    std::mt19937 g_engine(rd());
    std::shuffle(allTeams.begin(), allTeams.end(), g_engine);
    //Generate matchdays
    std::deque<int> idxs(allTeams.size());
    std::fill(idxs.begin(), idxs.end(), 0);

    calendar.resize(tours);
    for(int i = 0; i < tours; ++i){
        QVector<SCHEDULED_MATCH*> curMatchday;
        QVector<SCHEDULED_MATCH*> reversedCurMatchday;
        for(int game = 0; game < allTeams.size()/2; ++game){
            int ht = idxs[game * 2];
            int at = idxs[game * 2 + 1];
            curMatchday.push_back(new SCHEDULED_MATCH(GetNextIdAndIncr(), comp, allTeams[ht], allTeams[at]));
            curMatchday.push_back(new SCHEDULED_MATCH(GetNextIdAndIncr(), comp, allTeams[at], allTeams[ht]));
        }
        std::shuffle(curMatchday.begin(), curMatchday.end(), g_engine);
        std::shuffle(reversedCurMatchday.begin(), reversedCurMatchday.end(), g_engine);
        calendar[i] = curMatchday;
        calendar[tours + i] = reversedCurMatchday;
        int lastIdx = idxs.back();
        idxs.pop_back();
        idxs.push_front(lastIdx);
    }

    std::shuffle(calendar.begin(), std::next(calendar.begin(), allTeams.size() - 1), g_engine);

    //DATE startDate(QDateTime(QDate(start_year, ));
}

void LEAGUE_CALENDAR::Clear()
{
    calendar.clear();
}

QVector<SCHEDULED_MATCH *> LEAGUE_CALENDAR::GetTour(int id) const
{
    if(id >= calendar.size() || id < 0){
        qDebug() << "No such tour of calendar!";
    }
    return calendar[id];
}

QVector<SCHEDULED_MATCH *> LEAGUE_CALENDAR::GetTour(const QString &id) const
{
    for(int i = 0; i < toursNames.size(); ++i){
        if(id == toursNames[i]){
            return calendar[i];
        }
    }
    return QVector<SCHEDULED_MATCH*>{};
}

QString LEAGUE_CALENDAR::GetTourName(int id) const
{
    return toursNames[id];
}

void LEAGUE_CALENDAR::BindToursNames(QVector<QString> names)
{
    if(names.empty()){
        BindToursNamesDefault();
        return;
    }
    toursNames = names;
}

void LEAGUE_CALENDAR::BindToursNamesDefault()
{
    for(int i = 1; i <= (allTeams.size() - 1) * 2; ++i){
        toursNames.push_back("Matchday " + QString::number(i));
    }
}
