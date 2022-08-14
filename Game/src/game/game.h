#ifndef GAME_H
#define GAME_H

/* This class is meant to be the main game-processing class which is used to
 * handle events and data during simulation process
*/

#include "game/data/game_data.h"
#include "game/data/data_defs.h"
#include "game/events/event_handler.h"

class GAME
{
public:
    GAME(GAME_DATA* gameData, EVENT_HANDLER* eventHandler);
    ~GAME();

    void StartNewSeason(int year) noexcept;
    void InitBirthdaysEventsForTheFirstTime() noexcept;
private:
    void GenerateCalendars(int year) noexcept;
private:
    GAME_DATA* gameData;
    EVENT_HANDLER* eventHandler;
};

#endif // GAME_H
