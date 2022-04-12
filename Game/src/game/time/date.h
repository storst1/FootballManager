#ifndef DATE_H
#define DATE_H

#include <QString>
#include <QDate>

class DATE : public QDate
{
public:
    DATE(unsigned int rawDate);
    ~DATE() = default;

    bool operator==(const DATE& oth_date) const;
    bool operator!=(const DATE& oth_date) const;
    bool operator<(const DATE& oth_date) const;
    bool operator>(const DATE& oth_date) const;

    QString toStringView() const;

    static unsigned int rawDateFromTMDate(uint64_t TMDate);
private:
    unsigned int rawDate;
};

#endif // DATE_H
