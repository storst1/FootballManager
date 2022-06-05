#include "game/game.h"
#include "game/data/league.h"
#include "game/data/league_calendar.h"
#include "game/data/cup_calendar.h"
#include "game/data/player.h"
#include "game/events/event_birthday.h"

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

void GAME::InitBirthdaysEventsForTheFirstTime() noexcept
{
    DATE currentDate = eventHandler->getCurDate();
    QVector<PLAYER*> players = gameData->getPlayersList();
    for(const auto &cur_player : players){
        DATE nextBirthday = cur_player->getBirthday().findNextBirthday(currentDate, true);
        eventHandler->AddEvent(new EVENT_BIRTHDAY(nextBirthday, cur_player));
    }
}

void GAME::GenerateCalendars(int year) noexcept
{
    QVector<LEAGUE*> leagues = gameData->getLeaguesList();
    for(const auto &l : leagues){
        l->generateCalendar(year);
        l->getCalendar()->PassAllGamesToEventSystem(eventHandler);
    }
}
