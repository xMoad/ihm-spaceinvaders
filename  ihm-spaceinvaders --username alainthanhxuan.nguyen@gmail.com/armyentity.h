#ifndef ARMYENTITY_H
#define ARMYENTITY_H

#include <QTimer>
#include <QPainter>
#include <QPoint>
#include <QPainterPath>
#include "ArmyState/ArmyState.h"

class ArmyEntity:QObject
{
    Q_OBJECT
public:
    ArmyEntity();
    QTimer *autoMoveTimer;
    QPoint pos;

    bool isHit(QRect shot);
    void setIsAlive(bool b);
    bool getIsAlive();

private:
    bool isAlive;
    QPainterPath path;
    ArmyState *state;
    int widthOfSQuare, heightOfSQuare;

    void paint(QPainter &painter);
    void translate(int x, int y);
    void calculatePath();

public slots:
    void changeState();
};

#endif // ARMYENTITY_H
