#include "ArmyState1.h"

ArmyState1::ArmyState1():ArmyState(){}

ArmyState1::~ArmyState1()
{
}

int** ArmyState1::getMatrix()
{
    static const int state1[8][11] = {
            {0,0,1,0,0,0,0,0,1,0,0},
            {0,0,0,1,0,0,0,1,0,0,0},
            {0,0,1,1,1,1,1,1,1,0,0},
            {0,1,1,0,1,1,1,0,1,1,0},
            {1,1,1,1,1,1,1,1,1,1,1},
            {1,0,1,1,1,1,1,1,1,0,1},
            {1,0,1,0,0,0,0,0,1,0,1},
            {0,0,0,1,1,0,1,1,0,0,0}
        };
    return (int**)state1;
}
