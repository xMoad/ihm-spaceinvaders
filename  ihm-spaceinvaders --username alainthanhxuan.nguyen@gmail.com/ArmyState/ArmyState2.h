#ifndef ARMYSTATE2_H
#define ARMYSTATE2_H

#include "ArmyState.h"

class ArmyState2:public ArmyState
{
public:
    ArmyState2();
    virtual ~ArmyState2();
    virtual int** getMatrix();
};

#endif // ARMYSTATE2_H
