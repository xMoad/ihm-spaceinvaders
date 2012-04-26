#ifndef INVADERARMY_H
#define INVADERARMY_H

#include <QWidget>
#include <QObject>
#include <QPoint>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QPainter>
#include <iostream>
#include <QTimer>

#include "invadership.h"
#include "bullet.h"
#include "armyentity.h"

#define armyWidth 8
#define armyHeigth 2

#define dxarmy 2

#define fin -1

#define intervalShip 40
#define intervalRow 30

class InvaderArmy : public QWidget
{
    Q_OBJECT
public:
    //InvaderShip* invaderArmy[armyHeigth][armyWidth];
    ArmyEntity* invaderArmy[armyHeigth][armyWidth];

    int xmin, xmax, ymin, ymax;
    int leftEdgeI, rightEdgeI, bottomEdgeI;
    int leftEdgeP, rightEdgeP, bottomEdgeP;

    bool goRight, goLeft;
    bool end;

    int timerCount;
    QTimer *autoMoveTimer;

    explicit InvaderArmy(int width, int height, QWidget *parent = 0);
    void paintArmy(QPainter &painter);
    //void armyEdges(int rightEdge, int leftE, int topEdge, int bottomEdge);
    int defEdgeRight(int i);
    int defEdgeLeft(int i);
    int defEdgeBottom(int i);

    bool isHit(QRect shot);

private:    
    
signals:
    
public slots:
    void moveArmy();
    
};

#endif // INVADERARMY_H
