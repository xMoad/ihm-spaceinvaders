#include "ArmyState1.h"
#include <QList>
#include <QString>
#include <QImage>
#include <QApplication>

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
    pxm = QPixmap("../img/invader2.gif");
}

ArmyState1::~ArmyState1()
{}

QPixmap ArmyState1::getPixMap()
{
    return pxm;
}

int ArmyState1::getHeight()
{
    return pxm.height();
}

int ArmyState1::getWidth()
{
    return pxm.width();
}
