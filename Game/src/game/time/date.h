#ifndef DATE_H
#define DATE_H

#define FM_DATE_YEAR_MULT (unsigned int)1e4
#define FM_DATE_MONTH_MULT (unsigned int)1e2
#define FM_DATE_DAY_MULT (unsigned int)1

#include <QString>
#include <QDateTime>

#include <chrono>

class DATE : public QDateTime
{
public:
    DATE(unsigned int rawDate);
    DATE(QDateTime& qt_date);
    ~DATE() = default;

    unsigned int getRawDate() const;

    bool operator==(const DATE& oth_date) const;
    bool operator!=(const DATE& oth_date) const;
    bool operator<(const DATE& oth_date) const;
    bool operator>(const DATE& oth_date) const;

    QString toStringView() const;

    static unsigned int rawDateFromTMDate(uint64_t TMDate);
    static unsigned int rawDateFromQDateTime(const QDateTime& qt_time);
    static const QDate qtDateFromRawDate(unsigned int rawDate);
private:
    unsigned int rawDate;
};

#endif // DATE_H
