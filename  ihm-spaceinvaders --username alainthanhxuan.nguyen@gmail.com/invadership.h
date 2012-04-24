#ifndef INVADERSHIP_H
#define INVADERSHIP_H

#include <QWidget>
#include <QObject>
#include <QPoint>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QPainter>
#include <iostream>

using namespace std;

class InvaderShip : public QWidget
{
    Q_OBJECT

public:
    //InvaderShip(int width, int height, QWidget *parent = 0);
    InvaderShip(int posX, int posY, QWidget *parent = 0);

    QPoint pos;
    //int xmin, xmax;
    //int ymin, ymax;

    QRect invader;

    void fire();
    void paintShip(QPainter &painter);
    void setIsAlive(bool b);
    bool getIsAlive();

    bool isHit(QRect shot);
    void translate(int x, int y);

private:
    bool isAlive;


signals:

public slots:

};

#endif // INVADERSHIP_H
