#ifndef DATE_H
#define DATE_H

#include <QString>

class DATE
{
public:
    DATE(unsigned int rawDate);
    ~DATE() = default;

    bool operator==(const DATE& oth_date) const;
    bool operator!=(const DATE& oth_date) const;
    bool operator<(const DATE& oth_date) const;
    bool operator>(const DATE& oth_date) const;

    QString toStringView() const;
private:
    unsigned int rawDate;
};

#endif // DATE_H
