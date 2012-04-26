#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QWidget>
#include "playership.h"
#include <QPixmap>
#include "invaderarmy.h"

QT_BEGIN_NAMESPACE
class QTimer;
QT_END_NAMESPACE

class PlayerShip;
class InvaderArmy;

class BattleField : public QWidget
{
    Q_OBJECT

public:
    BattleField(QWidget *parent = 0);

    PlayerShip* playerShip;
    //InvaderShip* invaderShip;
    InvaderArmy* invaderArmy;
    int timerCount;
    QTimer *autoShootTimer;
    QPoint target;
    bool gameEnded;
    QPixmap background;

    void paintEvent(QPaintEvent *event);
    bool isHit(QRect shot);

    int getSizeX();
    int getSizeY();

    void newPlayer();
    void beginTimer();



public slots:
    //void newTarget();
    void restartGame();

    void goLeft();
    void goLeft(QKeyEvent* e);
    void goRight();
    void goRight(QKeyEvent *e);
    void fire();

signals:
    void hit();
    void missed();


};

#endif
