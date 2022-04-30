#include "game/data/player_position.h"

PLAYER_POSITION::PLAYER_POSITION()
{

}

PLAYER_POSITION::PLAYER_POSITION(int fp) : FP(fp), SP(0)
{

}

PLAYER_POSITION::PLAYER_POSITION(int fp, int sp) : FP(fp), SP(sp)
{

}

PLAYER_POSITION::PLAYER_POSITION(int fp, int sp, QString name) :
    FP(fp), SP(sp), strName(name)
{

}

QString PLAYER_POSITION::posIdToStr(int id)
{
    if(id == 1) return "GK";
    else if(id == 3) return "CB";
    else if(id == 4) return "LB";
    else if(id == 5) return "RB";
    else if(id == 6) return "DM";
    else if(id == 7) return "CM";
    else if(id == 8) return "RM";
    else if(id == 9) return "LM";
    else if(id == 10) return "CAM";
    else if(id == 11) return "LW";
    else if(id == 12) return "RW";
    else if(id == 13) return "CF";
    else if(id == 14) return "ST";
    //else
    return "?";
}

int PLAYER_POSITION::getFP() const
{
    return FP;
}

int PLAYER_POSITION::getSP() const
{
    return SP;
}

QString PLAYER_POSITION::getStrName() const
{
    return strName;
}

void PLAYER_POSITION::setStrNameToAuto()
{
    strName = PLAYER_POSITION::posIdToStr(FP);
    if(SP != 0){
        strName += "/" + posIdToStr(SP);
    }
    //qDebug() << strName;
}

void PLAYER_POSITION::NormalizePosId(int &pos, bool mainPos)
{
    if(pos == 2){
        mainPos ? pos = 3 : pos = 0;
    }
    else if(pos == 0 && mainPos){
        pos = PLAYER_POSITION::getRandPosId();
    }
}

int PLAYER_POSITION::getRandPosId()
{
    int pos = QRandomGenerator::global()->bounded(1, 15);
    if(pos == 2){
        pos = getRandPosId();
    }
    return pos;
}

void PLAYER_POSITION::NormalizeBothPosId(int &pos1, int &pos2)
{
    PLAYER_POSITION::NormalizePosId(pos1, true);
    PLAYER_POSITION::NormalizePosId(pos2, false);
    if(pos1 == pos2){
        pos2 = 0;
    }
}
