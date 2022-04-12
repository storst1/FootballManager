#include "date.h"

DATE::DATE(unsigned int rawDate) : rawDate(rawDate)
{

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

}
