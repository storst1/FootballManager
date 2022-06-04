#include "game/events/event_match.h"
#include "main/mainwindow.h"

EVENT_MATCH::EVENT_MATCH(SCHEDULED_MATCH *scheduledMatch) : EVENT(scheduledMatch->getDate(), EventType::Match), match(scheduledMatch)
{
    EVENT::order = EVENT::Order::Evening;
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

void EVENT_MATCH::paintEvent(QPainter &painter, int row, TEAM* team)
{
    TEAM* opponentTeam = match->getHT();
    bool homeGame = false;
    if(opponentTeam == team){
        opponentTeam = match->getAT();
        homeGame = true;
    }
    QPixmap teamIcon(MainWindow::GetClubLogoPath(static_cast<CLUB*>(opponentTeam)));
    painter.drawPixmap(100, row * 100 + 10, 50, 50, teamIcon);
    QPen pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);
    QFont font("Comic Sans MS", 10, 550);
    painter.setFont(font);
    QString mainText = opponentTeam->getName() + (homeGame ? " (H)" : " (A)");
    painter.drawText(70, row * 100 + 80, mainText);
    painter.drawText(70, row * 100 + 95, match->getComp()->getName());
}
