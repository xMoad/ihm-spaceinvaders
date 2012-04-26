#ifndef ARMYSTATE2_H
#define ARMYSTATE2_H

#include "ArmyState.h"
#include <QPixmap>
#include <QTimer>
#include <QString>

class ArmyState2:public ArmyState
{
    //Q_OBJECT
private:
    QPixmap* pxm;
    QPixmap currentPixmap;
    bool index;

public:
    ArmyState2();
    virtual ~ArmyState2();
    virtual QPixmap getPixMap();
    virtual int getHeight();
    virtual int getWidth();
    virtual QString getClassName();

public slots:
    virtual void animationSlot();
};
#endif // ARMYSTATE2_H
