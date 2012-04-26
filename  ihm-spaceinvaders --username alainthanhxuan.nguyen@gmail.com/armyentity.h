#ifndef ARMYENTITY_H
#define ARMYENTITY_H

#include <QTimer>
#include <QPainter>
#include <QPoint>
#include <QPainterPath>
#include "ArmyState/ArmyState.h"
#include <iostream>

using namespace std;

class ArmyEntity:QObject
{
    Q_OBJECT
public:
    ArmyEntity(int posX, int posY);
    QTimer *autoMoveTimer;
    QPoint pos;

    bool isHit(QRect shot);
    void setIsAlive(bool b);
    bool getIsAlive();
    void translate(int x, int y);
    void paint(QPainter &painter);

private:
    bool isAlive;
    QPainterPath path;
    ArmyState *state;
    int widthOfSQuare, heightOfSQuare;

    void calculatePath();

public slots:
    void changeState();
};

#endif // ARMYENTITY_H
