#include "date.h"

DATE::DATE(unsigned int rawDate) : QDateTime(), rawDate(rawDate)
{
    setDate(DATE::qtDateFromRawDate(rawDate)); //Filling in QDateTime parent class
}

DATE::DATE(QDateTime &qt_date) : QDateTime(qt_date)
{

}

unsigned int DATE::getRawDate() const
{
    return rawDate;
}

int DATE::Day() const
{
    return date().day();
}

int DATE::Month() const
{
    return date().month();
}

QString DATE::MonthName() const
{
    int month = Month();
    switch(month){
        case 1:
            return "January";
        case 2:
            return "Feburary";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "Jule";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Wrong input";
    }
}

int DATE::Year() const
{
    return date().year();
}

DATE DATE::NextDay()
{
    QDateTime QNewDate = addDays(1);
    return DATE(QNewDate);
}

DATE DATE::addDaysFM(int days)
{
    QDateTime QNewDate = addDays(days);
    return DATE(QNewDate);
}

bool DATE::operator==(const DATE &oth_date) const
{
    return rawDate == oth_date.rawDate;
}

bool DATE::operator!=(const DATE &oth_date) const
{
    return rawDate != oth_date.rawDate;
}

bool DATE::operator<(const DATE &oth_date) const
{
    return rawDate < oth_date.rawDate;
}

bool DATE::operator>(const DATE &oth_date) const
{
    return rawDate > oth_date.rawDate;
}

QString DATE::toStringView() const
{
    QString str = QString::number(rawDate);
    str.insert(4, '-');
    str.insert(7, '-');
    return str;
}

int DATE::agesPassedSince() const
{
    return DATE::agesPassedSince(rawDate);
}

unsigned int DATE::rawDateFromTMDate(uint64_t TMDate)
{
    QDateTime qt_date = QDateTime::fromSecsSinceEpoch(TMDate, Qt::TimeSpec::UTC);
    return rawDateFromQDateTime(qt_date);
}

unsigned int DATE::rawDateFromQDateTime(const QDateTime &qt_time)
{
    unsigned int curRawDate = 0;
    QDate qt_date = qt_time.date();
    curRawDate += qt_date.year() * FM_DATE_YEAR_MULT;
    curRawDate += qt_date.month() * FM_DATE_MONTH_MULT;
    curRawDate += qt_date.day() * FM_DATE_DAY_MULT;
    return curRawDate;
}

const QDate DATE::qtDateFromRawDate(unsigned int rawDate)
{
    int year = rawDate / FM_DATE_YEAR_MULT;
    rawDate %= FM_DATE_YEAR_MULT;
    int month = rawDate / FM_DATE_MONTH_MULT;
    rawDate %= FM_DATE_MONTH_MULT;
    int day = rawDate / FM_DATE_DAY_MULT;
    return QDate(year, month, day);
}

int DATE::generateRandomRawDate(int from, int to)
{
    return QRandomGenerator::global()->bounded(from, to);
}

int DATE::agesPassedSince(int rawDate)
{
    return (START_DATE - rawDate) / FM_DATE_YEAR_MULT;
}

DATE DATE::getBestLeagueStartingDate(int starting_year, int tours)
{
    QDate lastDay(starting_year, 12, 27);
    while(lastDay.dayOfWeek() != 5){
        lastDay = lastDay.addDays(-1);
    }
    lastDay = lastDay.addDays(-7 * (tours / 2 - 1));
    QTime t;
    QDateTime qt(lastDay, t);
    return DATE(qt);
}
