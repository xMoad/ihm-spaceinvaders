#ifndef ARMYSTATE1_H
#define ARMYSTATE1_H

#include "ArmyState.h"
#include <QPixmap>
#include <iostream>
#include <QString>
#include <QTimer>

using namespace std;

class ArmyState1:public ArmyState
{
    //Q_OBJECT
private:
   // int **state1;
    //QList<QList<int> > state1;
    //static const int width = 11;
    //static const int height = 8;
    QPixmap* pxm;
    QPixmap currentPixmap;

public:
    ArmyState1();
    virtual ~ArmyState1();
    virtual QPixmap getPixMap();
    virtual int getHeight();
    virtual int getWidth();

    //QTimer* animationTimer;
//public slots:
    //void changeImg();

};

#endif // ARMYSTATE1_H
