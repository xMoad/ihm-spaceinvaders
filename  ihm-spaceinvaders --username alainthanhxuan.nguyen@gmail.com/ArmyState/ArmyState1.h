#ifndef ARMYSTATE1_H
#define ARMYSTATE1_H

#include "ArmyState.h"
#include <QList>
#include <QPixmap>
#include <iostream>
#include <QString>

using namespace std;

class ArmyState1:public ArmyState
{
private:
   // int **state1;
    //QList<QList<int> > state1;
    //static const int width = 11;
    //static const int height = 8;
    QPixmap pxm;

public:
    ArmyState1();
    virtual ~ArmyState1();
    //virtual int** getMatrix();
    virtual QPixmap getPixMap();
    virtual int getHeight();
    virtual int getWidth();
};

#endif // ARMYSTATE1_H
