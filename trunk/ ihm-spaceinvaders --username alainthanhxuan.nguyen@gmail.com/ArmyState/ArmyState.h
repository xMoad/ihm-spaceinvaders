#ifndef ARMYSTATE_H
#define ARMYSTATE_H
#include <QPixmap>
#include <QList>

using namespace std;

class ArmyState
{

public:
    ArmyState();
    virtual ~ArmyState();
    //virtual vector< vector<int> > getMatrix()=0;
    //virtual int **getMatrix()=0;
    virtual QPixmap getPixMap()= 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
};

#endif // ARMYSTATE_H
