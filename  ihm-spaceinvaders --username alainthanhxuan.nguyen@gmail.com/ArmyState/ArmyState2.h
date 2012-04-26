#ifndef ARMYSTATE2_H
#define ARMYSTATE2_H

#include "ArmyState.h"
#include <QList>

class ArmyState2:public ArmyState
{
public:
    ArmyState2();
    QList<QList<int> > state2;
    virtual ~ArmyState2();
    //virtual int** getMatrix();
    virtual QList<QList<int> >  getMatrix();
};

#endif // ARMYSTATE2_H
