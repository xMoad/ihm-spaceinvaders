#include "ArmyState1.h"
#include <QPixmap>
#include <QTimer>
#include <iostream>

using namespace std;

ArmyState1::ArmyState1():ArmyState()
{
//    int arr[height][width] = {
//                {0,0,1,0,0,0,0,0,1,0,0},
//                {0,0,0,1,0,0,0,1,0,0,0},
//                {0,0,1,1,1,1,1,1,1,0,0},
//                {0,1,1,0,1,1,1,0,1,1,0},
//                {1,1,1,1,1,1,1,1,1,1,1},
//                {1,0,1,1,1,1,1,1,1,0,1},
//                {1,0,1,0,0,0,0,0,1,0,1},
//                {0,0,0,1,1,0,1,1,0,0,0}
//            };
//    state1 = new int*[width];
//    for(int i = 0; i < width; i++)
//    {
//        state1[i] = new int[height];
//        for(int j=0;j<height;j++)
//        {
//            state1[i][j] = arr[i][j];
//            //cout<<state1[i][j];
//        }
//    }
//    state1 =  QList< QList<int> >();
//    for(int i = 0; i < height; i++)
//    {
//        QList<int> lst = QList<int>();
//        for(int j=0;j<width;j++)
//        {
//            lst.append(arr[i][j]);
//            lst[j];
//        }
//        state1.append(lst);
//    }
    name = "state1";
    pxm = new QPixmap[2];
    pxm[0] = QPixmap("../img/invader2.gif");
    pxm[1] = QPixmap("../img/invader2c.gif");
    currentPixmap = pxm[0];

    //animationTimer =  new QTimer(this);
    //connect(animationTimer,SIGNAL(timeout()),this,SLOT(changeImg()));
    animationTimer->start(400);
    index = true;
}

ArmyState1::~ArmyState1(){
    delete pxm;
}

QPixmap ArmyState1::getPixMap()
{
    return currentPixmap;
}

int ArmyState1::getHeight()
{
    return currentPixmap.height();
}

int ArmyState1::getWidth()
{
    return currentPixmap.width();
}

void ArmyState1::animationSlot()
{
    index = !index;
    currentPixmap = pxm[(int)index];
    animationTimer->stop();
    animationTimer->start(400);
}

QString ArmyState1::getClassName(){
    return name;
}
