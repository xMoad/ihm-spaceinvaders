#include "ArmyState2.h"
#include <vector>

ArmyState2::ArmyState2():ArmyState(){}

ArmyState2::~ArmyState2()
{
}

int **ArmyState2::getMatrix()
{
     static const int state2[8][11] = {
        {0,0,1,0,0,0,0,0,1,0,0},
        {1,0,0,1,0,0,0,1,0,0,1},
        {1,0,1,1,1,1,1,1,1,0,1},
        {1,1,1,0,1,1,1,0,1,1,1},
        {0,1,1,1,1,1,1,1,1,1,0},
        {0,0,1,1,1,1,1,1,1,0,0},
        {0,0,1,0,0,0,0,0,1,0,0},
        {0,0,0,1,1,0,1,1,0,0,0}
    };
     return (int**)state2;
}
