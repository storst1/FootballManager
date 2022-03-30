#ifndef GAME_DATA_H
#define GAME_DATA_H

#include "game/data/data_defs.h"

#include <QMap>

class GAME_DATA
{
public:
    GAME_DATA();
    ~GAME_DATA();

    QMap<int, FEDERATION*> getFederations();
    QMap<QString, LEAGUE*> getLeagues();
    QMap<int, CLUB*> getClubs();
    QMap<int, PLAYER*> getPlayers();

    void addFederation(FEDERATION* fed);
    void addFederations(QList<FEDERATION*>& listFed);
    void addLeague(LEAGUE* league);
    void addLeagues(QList<LEAGUE*>& listLeague);
    void addClub(CLUB* club);
    void addClubs(QList<CLUB*>& listClubs);
    void addPlayer(PLAYER* player);
    void addPlayers(QList<PLAYER*>& listPlayers);
private:
    FIFA* fifa;
    QMap<int, FEDERATION*> federations;
    QMap<QString, LEAGUE*> leagues;
    QMap<int, CLUB*> clubs;
    QMap<int, PLAYER*> players;
};

#endif // GAME_DATA_H
