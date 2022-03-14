#ifndef CLUB_H
#define CLUB_H

#include <QString>

class CLUB
{
public:
    CLUB();
    CLUB(int id);
    ~CLUB() = default;
private:
    int id;
    QString name;
};

#endif // CLUB_H
