#ifndef LEAGUE_H
#define LEAGUE_H

#include "game/data/data_defs.h"
#include "game/data/competition.h"

class LEAGUE : public COMPETITION
{
public:
    LEAGUE();
    ~LEAGUE();

    int getTier() const;
    void setTier(int t);

    void setupCalendar() override;
    void generateCalendar(int year) override;
private:
    int tier;

    //CUP* leagueCup = nullptr; //may be nullptr

    //stats fields
    TABLE* table;
};

#endif // LEAGUE_H
