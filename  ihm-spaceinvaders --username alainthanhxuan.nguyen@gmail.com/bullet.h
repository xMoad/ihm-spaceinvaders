#ifndef BULLET_H
#define BULLET_H

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

#include "battlefield.h"
class BattleField;

class Bullet : public QWidget
{
    Q_OBJECT

public:
    explicit Bullet(QPoint posShip, BattleField* battleField,
                    QWidget *parent = 0);

    BattleField* battleField;
    QPoint posShot;
    int xmin, xmax;
    int ymin, ymax;

    int timerCount;
    QTimer *autoShootTimer;

    void paintShot(QPainter &painter);
    QRect shotRect() const;

    void moveShot();

signals:
    
public slots:
    
};

#endif // BULLET_H
