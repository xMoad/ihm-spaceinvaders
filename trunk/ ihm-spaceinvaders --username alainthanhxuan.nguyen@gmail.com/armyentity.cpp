#include <QRect>
#include "ArmyState/ArmyState1.h"
#include "ArmyState/ArmyState2.h"
#include "invaderarmy.h"
#include "armyentity.h"

ArmyEntity::ArmyEntity(int indexI, int indexJ, QObject* parent)
{
    state = new ArmyState1();

    pos.setX(state->getWidth()*indexI+InvaderArmy::intervalShip);
    pos.setY(state->getHeight()*indexJ+InvaderArmy::intervalRow);
    cout << "posX: " << pos.x() << " posY: " << pos.y() << endl;

    autoTimer = new QTimer(this);
    connect(autoTimer,SIGNAL(timeout()),this,SLOT(changeState()));
    autoTimer->start(5000);
    isAlive = true;
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
        //path.addRect(target);
        rect = target;


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
        if(rect.intersects(shot)){
            isAlive = false;
            cout << "BOUM" << endl;
            return true;
        }
    return false;
}


void ArmyEntity::translate(int x, int y){
    pos.setX(pos.x() + x);
    pos.setY(pos.y() + y);
}

void ArmyEntity::changeState()
{
    if(state->getClassName() == "state1")
    {
        state = new ArmyState2();
    }else
        state = new ArmyState1();
    autoTimer->stop();
    autoTimer->start(5000);
}
