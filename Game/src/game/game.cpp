#include "game/game.h"
#include "game/data/league.h"
#include "game/data/league_calendar.h"
#include "game/data/cup_calendar.h"

GAME::GAME(GAME_DATA *gameData, EVENT_HANDLER *eventHandler) : gameData(gameData), eventHandler(eventHandler)
{

}

GAME::~GAME()
{

}

void GAME::StartNewSeason(int year) noexcept
{
    GenerateCalendars(year);
}

void GAME::GenerateCalendars(int year) noexcept
{
    QVector<LEAGUE*> leagues = gameData->getLeaguesList();
    for(const auto &l : leagues){
        l->generateCalendar(year);
        l->getCalendar()->PassAllGamesToEventSystem(eventHandler);
    }
}
