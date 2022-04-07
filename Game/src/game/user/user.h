#ifndef USER_H
#define USER_H

#include "game/data/data_defs.h"

class USER
{
public:
    USER();
    ~USER() = default;

    CLUB *getClub() const;

    void setClub(CLUB* curClub);
private:
    CLUB* club = nullptr;
};

#endif // USER_H
