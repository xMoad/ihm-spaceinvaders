#include "armyentity.h"

#include <QTimer>
#include <QPainter>
#include <QPoint>
#include <QPainterPath>
#include <QRect>
#include "ArmyState/ArmyState1.h"
#include "ArmyState/ArmyState2.h"

ArmyEntity::ArmyEntity(int posX, int posY)
{
    state = new ArmyState1();

    cout << "posX: " << posX << " posY: " << posY << endl;
    pos.setX(posX);
    pos.setY(posY);

    isAlive = true;
    widthOfSQuare = 10;
    heightOfSQuare = 10;
}

void ArmyEntity::paint(QPainter &painter){

    if(isAlive){
        this->calculatePath();

        QPen pen;
        pen.setColor(Qt::blue);
        pen.setWidth(2);

        painter.setPen(pen);
        painter.setBrush(Qt::blue);
        painter.drawPath(path);
    }

}

void ArmyEntity::setIsAlive(bool b){
    isAlive = b;
}

bool ArmyEntity::getIsAlive(){
    return isAlive;
}

bool ArmyEntity::isHit(QRect shot){
    if(isAlive){
        if(path.intersects(shot)){
            isAlive = false;
            cout << "BOUM" << endl;
            return true;
        }
    }
    return false;
}


void ArmyEntity::translate(int x, int y){
    pos.setX(pos.x() + x);
    pos.setY(pos.y() + y);
}

void ArmyEntity::changeState()
{

}

void ArmyEntity::calculatePath()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            if(state->getMatrix()[i][j] == 1)
            {
                QRect rect = QRect(pos.x()+i*widthOfSQuare,pos.y()+j*heightOfSQuare,widthOfSQuare, widthOfSQuare);
                path.addRect(rect);
            }
        }
    }
}
