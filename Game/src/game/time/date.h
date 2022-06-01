#ifndef DATE_H
#define DATE_H

#define FM_DATE_YEAR_MULT (unsigned int)1e4
#define FM_DATE_MONTH_MULT (unsigned int)1e2
#define FM_DATE_DAY_MULT (unsigned int)1

#define START_DATE 20210801

#include <QString>
#include <QDateTime>
#include <QRandomGenerator>
#include <QDate>

#include <chrono>

class DATE : public QDateTime
{
public:
    DATE() = default;
    DATE(unsigned int rawDate);
    DATE(QDateTime& qt_date);
    //DATE(DATE& oth);
    ~DATE() = default;

    unsigned int getRawDate() const;

    int Day() const;
    int Month() const;
    QString MonthName() const;
    int Year() const;

    DATE NextDay();
    DATE addDaysFM(int days);

    bool operator==(const DATE& oth_date) const;
    bool operator!=(const DATE& oth_date) const;
    bool operator<(const DATE& oth_date) const;
    bool operator>(const DATE& oth_date) const;

    QString toStringView() const;
    int agesPassedSince() const;

    static unsigned int rawDateFromTMDate(uint64_t TMDate);
    static unsigned int rawDateFromQDateTime(const QDateTime& qt_time);
    static const QDate qtDateFromRawDate(unsigned int rawDate);
    static int generateRandomRawDate(int from = 19820101, int to = 20061231);
    static int agesPassedSince(int rawDate);
    static DATE getBestLeagueStartingDate(int starting_year, int tours);
private:
    unsigned int rawDate = 0;
};

#endif // DATE_H
