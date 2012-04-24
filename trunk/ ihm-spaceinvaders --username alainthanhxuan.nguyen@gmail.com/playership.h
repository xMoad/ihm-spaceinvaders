#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <QWidget>
#include <QObject>
//#include <QMouseEvent>
#include <QPoint>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QPainter>
#include <iostream>
#include <QTimer>

#include "bullet.h"
#include "battlefield.h"

#define dxplayer 2

using namespace std;
class BattleField;
class Bullet;

class PlayerShip : public QWidget
{
    Q_OBJECT

public:
    PlayerShip(int x, int y, BattleField* battleField, QWidget *parent = 0);
    Bullet* bullet;
    BattleField* battleField;

    QPoint posShip;
    int xmin, xmax;
    int ymin, ymax;

    bool getHit();
    void setHit();
    void paintShip(QPainter &painter);

    void fireShot();
    bool isShooting() const;

    
signals:
    void canShoot(bool can);
    
public slots:
    void goLeft();
    void goRight();
    void moveShot();

    
};

#endif // PLAYERSHIP_H
