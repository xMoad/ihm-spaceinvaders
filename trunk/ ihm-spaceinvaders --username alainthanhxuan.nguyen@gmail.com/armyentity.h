#ifndef ARMYENTITY_H
#define ARMYENTITY_H

#include <QTimer>
#include <QPainter>
#include <QPoint>
#include <QPainterPath>
#include "ArmyState/ArmyState.h"
#include <iostream>

using namespace std;

class ArmyEntity:public QObject
{
    Q_OBJECT
public:
    ArmyEntity(int indexI, int indexJ, QObject* parent=0);
    QTimer *autoTimer;
    QPoint pos;

    bool isHit(QRect shot);
    void setIsAlive(bool b);
    bool getIsAlive();
    void translate(int x, int y);
    void paint(QPainter &painter);

private:
    bool isAlive;
    QPainterPath path;
    QRect rect;
    ArmyState *state;

public slots:
    void changeState();
};

#endif // ARMYENTITY_H
