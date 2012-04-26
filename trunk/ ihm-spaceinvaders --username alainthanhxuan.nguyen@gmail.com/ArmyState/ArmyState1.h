#ifndef ARMYSTATE1_H
#define ARMYSTATE1_H

#include "ArmyState.h"
#include <QPixmap>
#include <QTimer>
#include <QString>

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
    bool index;

public:
    ArmyState1();
    virtual ~ArmyState1();
    virtual QPixmap getPixMap();
    virtual int getHeight();
    virtual int getWidth();
    virtual QString getClassName();

    //QTimer* animationTimer;
public slots:
    virtual void animationSlot();
};
#endif // ARMYSTATE1_H
