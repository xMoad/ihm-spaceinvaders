#include "armyentity.h"

#include <QTimer>
#include <QPainter>
#include <QPoint>
#include <QPainterPath>
#include <QRect>
#include <QList>
#include "ArmyState/ArmyState1.h"
#include "ArmyState/ArmyState2.h"

ArmyEntity::ArmyEntity(int posX, int posY)
{
    state = new ArmyState1();

    cout << "posX: " << posX << " posY: " << posY << endl;
    pos.setX(posX);
    pos.setY(posY);

    isAlive = true;
    widthOfSQuare = 2;
    heightOfSQuare = 2;
}

void ArmyEntity::paint(QPainter &painter){

    if(isAlive){
        //this->calculatePath();

        QPen pen;
        pen.setColor(Qt::blue);
        pen.setWidth(2);

        QPixmap pxm = state->getPixMap();
        QRect target = QRect(pos.x(),pos.y(),pxm.width()-15,pxm.height()-15);
        QRect source = QRect(0,0,pxm.width(),pxm.height());

        painter.setPen(pen);
        painter.setBrush(Qt::blue);
        painter.drawPixmap(target,pxm,source);
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
//    QList< QList<int> > l = state->getMatrix();
//    for(int i = 0; i < l.count(); i++)
//    {
//        for(int j = 0; j < l[i].count(); j++)
//        {
//            if(l[i][j] == 1)
//            {
//                QRect rect = QRect(pos.x()+i*widthOfSQuare,pos.y()+j*heightOfSQuare,widthOfSQuare, widthOfSQuare);
//                path.addRect(rect);
//            }
//        }
//    }

}
