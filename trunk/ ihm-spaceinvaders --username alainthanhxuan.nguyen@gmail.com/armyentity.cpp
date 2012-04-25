#include "armyentity.h"

#include <QTimer>
#include <QPainter>
#include <QPoint>

ArmyEntity::ArmyEntity()
{
    static const int state1[8][11] = {
        {0,0,1,0,0,0,0,0,1,0,0},
        {0,0,0,1,0,0,0,1,0,0,0},
        {0,0,1,1,1,1,1,1,1,0,0},
        {0,1,1,0,1,1,1,0,1,1,0},
        {1,1,1,1,1,1,1,1,1,1,1},
        {1,0,1,1,1,1,1,1,1,0,1},
        {1,0,1,0,0,0,0,0,1,0,1},
        {0,0,0,1,1,0,1,1,0,0,0}
   };

    static const int state2[8][11] = {
        {0,0,1,0,0,0,0,0,1,0,0},
        {1,0,0,1,0,0,0,1,0,0,1},
        {1,0,1,1,1,1,1,1,1,0,1},
        {1,1,1,0,1,1,1,0,1,1,1},
        {0,1,1,1,1,1,1,1,1,1,0},
        {0,0,1,1,1,1,1,1,1,0,0},
        {0,0,1,0,0,0,0,0,1,0,0},
        {0,0,0,1,1,0,1,1,0,0,0}
   };

    isAlive = true;
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
