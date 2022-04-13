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


