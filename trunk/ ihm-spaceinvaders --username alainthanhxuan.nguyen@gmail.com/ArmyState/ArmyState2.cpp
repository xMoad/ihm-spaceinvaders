#include "ArmyState2.h"
#include <QPixmap>
#include <QTimer>
#include <iostream>
#include <QString>

using namespace std;

ArmyState2::ArmyState2():ArmyState()
{
    pxm = new QPixmap[2];
    pxm[0] = QPixmap(":/img/invader1.gif");
    pxm[1] = QPixmap(":/img/invader1c.gif");
    currentPixmap = pxm[0];

    name = "state2";
    animationTimer->start(400);
    index = true;
}

ArmyState2::~ArmyState2(){
    delete pxm;
}

QPixmap ArmyState2::getPixMap()
{
    return currentPixmap;
}

int ArmyState2::getHeight()
{
    return currentPixmap.height();
}

int ArmyState2::getWidth()
{
    return currentPixmap.width();
}

void ArmyState2::animationSlot()
{
    index = !index;
    currentPixmap = pxm[(int)index];
    animationTimer->stop();
    animationTimer->start(400);
}

QString ArmyState2::getClassName(){
    return name;
}
