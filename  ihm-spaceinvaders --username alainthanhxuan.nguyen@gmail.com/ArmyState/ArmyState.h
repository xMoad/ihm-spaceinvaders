#ifndef ARMYSTATE_H
#define ARMYSTATE_H
#include <QPixmap>
#include <QObject>
#include <QTimer>

class ArmyState:public QObject
{
    Q_OBJECT
public:
    ArmyState(QObject *parent = 0);
    virtual ~ArmyState();
    //virtual vector< vector<int> > getMatrix()=0;
    virtual QPixmap getPixMap()= 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
protected:
    QTimer* animationTimer;
public slots:
    virtual void animationSlot();
};

#endif // ARMYSTATE_H
