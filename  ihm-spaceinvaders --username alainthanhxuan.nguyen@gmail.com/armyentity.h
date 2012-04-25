#ifndef ARMYENTITY_H
#define ARMYENTITY_H

#include <QTimer>
#include <QPainter>
#include <QPoint>

enum state {state1,state2};

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

    void paint(QPainter &painter);
    void translate(int x, int y);

public slots:
    void changeState();
};

#endif // ARMYENTITY_H
