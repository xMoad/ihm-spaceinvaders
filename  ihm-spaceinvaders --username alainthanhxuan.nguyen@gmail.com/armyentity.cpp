#include "armyentity.h"

#include <QTimer>
#include <QPainter>
#include <QPoint>
#include <QPainterPath>
#include <QRect>
#include "ArmyState/ArmyState1.h"
#include "ArmyState/ArmyState2.h"

ArmyEntity::ArmyEntity()
{
    isAlive = true;
    state = new ArmyState2();
    widthOfSQuare = 10;
    heightOfSQuare = 10;
}

void ArmyEntity::paint(QPainter &painter){

    if(isAlive){
        //QPolygonF polygon;
        QPen pen;
        pen.setColor(Qt::blue);
        pen.setWidth(2);

        /*polygon << QPointF(pos.x(), pos.y())
                << QPointF(pos.x()+20, pos.y()-10)
                << QPointF(pos.x()-20, pos.y()-10)
                << QPointF(pos.x(), pos.y());

        painter.setPen(pen);
        painter.setBrush(Qt::blue);
        painter.drawPolygon(polygon, Qt::WindingFill);*/


        QRect invaderRect(pos.x(), pos.y(), 10, 10);
        painter.setPen(pen);
        painter.setBrush(Qt::blue);
        painter.drawPolygon(invaderRect, Qt::WindingFill);

        //invader = invaderRect;
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
        //        if(shot.intersects(this->invader)){
        //            isAlive = false;
        //            cout << "BOUM" << endl;
        //            return true;
        //        }
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
            //                if(ArmyEntity.state1[i][j] == 1)
            //                {
            //                    QRect rect = QRect(pos.x()+i*widthOfSQuare,pos.y()+j*heightOfSQuare,widthOfSQuare, widthOfSQuare);
            //                    path.addRect(rect);
            //                }
        }
    }
}
