#ifndef GAME_H
#define GAME_H

#include "game/data/game_data.h"
#include "game/data/data_defs.h"
#include "game/events/event_handler.h"

class GAME
{
public:
    GAME(GAME_DATA* gameData, EVENT_HANDLER* eventHandler);
    ~GAME();

    void StartNewSeason(int year) noexcept;
private:
    void GenerateCalendars(int year) noexcept;
private:
    GAME_DATA* gameData;
    EVENT_HANDLER* eventHandler;
};

#endif // GAME_H
