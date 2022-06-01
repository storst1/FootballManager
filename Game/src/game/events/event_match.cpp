#include "game/events/event_match.h"
#include "main/mainwindow.h"

EVENT_MATCH::EVENT_MATCH(SCHEDULED_MATCH *scheduledMatch) : EVENT(scheduledMatch->getDate(), EventType::Match), match(scheduledMatch)
{

}

void EVENT_MATCH::Execute()
{
    //match->Play();
}

bool EVENT_MATCH::IsLinkedToTeam(TEAM* team) const
{
    if(match->getHT() == team || match->getAT() == team){
        return true;
    }
    return false;
}

void EVENT_MATCH::paintEvent(QPainter &painter, int row)
{
    QPixmap teamIcon(MainWindow::GetClubLogoPath(static_cast<CLUB*>(match->getHT())));
    painter.drawPixmap(100, row * 100 + 10, 50, 50, teamIcon);
    QPen pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);
    QFont font("Comic Sans MS", 10, 550);
    painter.setFont(font);
    painter.drawText(80, row * 100 + 75, match->getHT()->getName());
}
