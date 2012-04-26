#include "invadership.h"

/*InvaderShip::InvaderShip(int width, int height, QWidget *parent)
    : QWidget(parent)
{
    cout << "width: " << width << " height: " << height << endl;
    pos.setX(width/2);
    pos.setY(20);

    xmax = width-20, xmin = 20;
    ymax = height-50, ymin= 20;
}*/

InvaderShip::InvaderShip(int posX, int posY)
{
    cout << "posX: " << posX << " posY: " << posY << endl;
    pos.setX(posX);
    pos.setY(posY);

    isAlive = true;
}

void InvaderShip::paint(QPainter &painter){

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

        invader = invaderRect;
    }

}

void InvaderShip::fire(){

}

void InvaderShip::setIsAlive(bool b){
    isAlive = b;
}

bool InvaderShip::getIsAlive(){
    return isAlive;
}


bool InvaderShip::isHit(QRect shot){
    if(isAlive){
        if(shot.intersects(this->invader)){
            isAlive = false;
            cout << "BOUM" << endl;
            return true;
        }
    }
    return false;
}


void InvaderShip::translate(int x, int y){
    pos.setX(pos.x() + x);
    pos.setY(pos.y() + y);
}
