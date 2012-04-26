#ifndef ARMYSTATE1_H
#define ARMYSTATE1_H

#include "ArmyState.h"

class ArmyState1:public ArmyState
{
public:
    ArmyState1();
    virtual ~ArmyState1();
    virtual int** getMatrix();
};

#endif // ARMYSTATE1_H
