#include "playership.h"


PlayerShip::PlayerShip(int width, int height,
                       BattleField *battleField, QWidget *parent)
    : QWidget(parent)
{
    cout << "width: " << width << " height: " << height << endl;
    posShip.setX(width/2);
    posShip.setY(height -20);

    xmax = width-20, xmin = 20;
    ymax = 0, ymin= height-20;

    this->battleField = battleField;

    //emit canShoot(true);
    connect(battleField->autoShootTimer, SIGNAL(timeout()),
            this, SLOT(moveShot()));

}


void PlayerShip::paintShip (QPainter &painter){

    /*if (isHit) {
        painter.setPen(Qt::red);
        painter.setFont(QFont("Courier", 48, QFont::Bold));
        painter.drawText(rect(), Qt::AlignCenter, tr("Game Over"));
    }*/

    QPolygonF polygon;

    polygon << QPointF(posShip.x(), posShip.y())
            << QPointF(posShip.x()+10, posShip.y()+10)
            << QPointF(posShip.x()-10, posShip.y()+10)
            << QPointF(posShip.x(), posShip.y());


    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(2);

    painter.setPen(pen);
    painter.setBrush(Qt::blue);
    painter.drawPolygon(polygon, Qt::WindingFill);
}


void PlayerShip::goLeft(){
    cout << "goLeft" << endl;
    cout << "initial: " << posShip.x();
    if(posShip.x()-dxplayer>xmin){
        posShip.setX(posShip.x() - dxplayer);
    }
    cout << " ,final: " << posShip.x() << endl;
}

void PlayerShip::goRight(){
    cout << "goRight" << endl;
    cout << "initial: " << posShip.x();
    if(posShip.x()+dxplayer<xmax){
        posShip.setX(posShip.x() + dxplayer);
    }
    cout << " ,final: " << posShip.x() << endl;
}


bool PlayerShip::isShooting() const{
    return battleField->autoShootTimer->isActive();
}


void PlayerShip::fireShot(){
    if(isShooting()) return;

    bullet = new Bullet(posShip, battleField);
    battleField->beginTimer();

    //emit canShoot(false);
}


void PlayerShip::moveShot(){
    bullet->moveShot();
}

