#include "bullet.h"

Bullet::Bullet(QPoint posShip, BattleField* battleField, QWidget *parent) :
    QWidget(parent)
{
    posShot.setX(posShip.x());
    posShot.setY(posShip.y());

    this->battleField = battleField;
    cout << "Bullet, " << "posShotX: " << posShot.x() <<
            " posShotY: " << posShot.y() << endl;
}

void Bullet::paintShot(QPainter &painter){
    cout << "paintShot" << endl;
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::yellow);
    painter.drawRect(shotRect());
}

QRect Bullet::shotRect() const{
    cout << "shotRect" << endl;
    QRect shot(0, 0, 6, 6);
    //double shootAngle = 90;
    double time = battleField->timerCount;
    double velocity = 2;

    //double rad = shootAngle * 3.14159265 / 180;
    double velx = 0; //velocity * cos(rad);
    double vely = - velocity * 1; //-velocity * sin(rad);

    double x = posShot.x() + velx * time;
    double y = posShot.y() + vely * time;

    shot.moveCenter(QPoint(qRound(x), qRound(y)));
    cout << "xShot: " << shot.x() << " yShot: " << shot.y();
    cout << ", shotWidth: " << shot.width() << " shotHeight: " << shot.height() << endl;

    return shot;
}


void Bullet::moveShot(){
    cout << "moveShot" << endl;
    QRegion region = shotRect();

    QRect shotR = shotRect();

    /*if (battleField->isHit(shotR)) return;
    else {
        region = region.united(shotR);
    }*/

    battleField->isHit(shotR);
    if (battleField->invaderArmy->isHit(shotR)){
        battleField->autoShootTimer->stop();
        return;
    }
    else if(shotR.y() < 0){
        cout << "MISSED" << endl;
        battleField->autoShootTimer->stop();
    }
    else region = region.united(shotR);

    update(region);
}
