#include "game/events/event_birthday.h"

EVENT_BIRTHDAY::EVENT_BIRTHDAY(DATE date, PLAYER* birthdayPlayer) :
    EVENT(date), player(birthdayPlayer)
{
    EVENT::order = EVENT::Morning;
    EVENT::eventType = EVENT::Birthday;
}

void EVENT_BIRTHDAY::Execute()
{
    player->addOneYearToAge();
    //TO DO: perhaps add morale boost here or smth similar
}

bool EVENT_BIRTHDAY::IsLinkedToTeam(TEAM team) const
{
    if(player->getClub()->getId() == team.getId()){
        return true;
    }
    return false;
}

void EVENT_BIRTHDAY::paintEvent(QPainter &painter, int row)
{
    QPixmap birthdayIcon(":/birthdayIcon100x133.png");
    painter.drawPixmap(100, row * 100 + 10, 50, 50, birthdayIcon);
    QPen pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);
    QFont font("Comic Sans MS", 10, 550);
    painter.setFont(font);
    painter.drawText(80, row * 100 + 75, player->getName());
}
