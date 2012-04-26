#ifndef ARMYSTATE_H
#define ARMYSTATE_H

using namespace std;

class ArmyState
{

public:
    int i;
    ArmyState();
    virtual ~ArmyState();
    //virtual vector< vector<int> > getMatrix()=0;
    virtual int **getMatrix()=0;
};

#endif // ARMYSTATE_H
