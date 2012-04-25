#include "invaderarmy.h"

InvaderArmy::InvaderArmy(int width, int height, QWidget *parent) :
    QWidget(parent)
{
    static const int etat1[8][11] = {
        {0,0,1,0,0,0,0,0,1,0,0},
        {0,0,0,1,0,0,0,1,0,0,0},
        {0,0,1,1,1,1,1,1,1,0,0},
        {0,1,1,0,1,1,1,0,1,1,0},
        {1,1,1,1,1,1,1,1,1,1,1},
        {1,0,1,1,1,1,1,1,1,0,1},
        {1,0,1,0,0,0,0,0,1,0,1},
        {0,0,0,1,1,0,1,1,0,0,0}
   };

    static const int etat2[8][11] = {
        {0,0,1,0,0,0,0,0,1,0,0},
        {1,0,0,1,0,0,0,1,0,0,1},
        {1,0,1,1,1,1,1,1,1,0,1},
        {1,1,1,0,1,1,1,0,1,1,1},
        {0,1,1,1,1,1,1,1,1,1,0},
        {0,0,1,1,1,1,1,1,1,0,0},
        {0,0,1,0,0,0,0,0,1,0,0},
        {0,0,0,1,1,0,1,1,0,0,0}
   };

    xmax = width-20, xmin = 20;
    ymin = 20, ymax= height-20;

    leftEdgeI=0, rightEdgeI=armyWidth-1, bottomEdgeI=armyHeigth-1;
    leftEdgeP=xmin,
            rightEdgeP=xmin+intervalShip*(armyWidth-1),
            bottomEdgeP=ymin+intervalRow*(armyHeigth-1);

    cout << "constructeur: " << endl;
    cout << "leftEdgeP: " << leftEdgeP << ", rightEdgeP: " << rightEdgeP
         << ", bottomEdgeP: " << bottomEdgeP << endl;
    cout << "width: " << width << ", height" << height << endl;

    for(int i=0; i<armyHeigth; i++){
        for(int j=0; j<armyWidth; j++){
            invaderArmy[i][j] = new InvaderShip(xmin + intervalShip*j,
                                                ymin + intervalRow*i);
        }
    }

    goLeft = false;
    goRight = true;
    end = false;

    autoMoveTimer = new QTimer(this);
    timerCount = 0;
    autoMoveTimer->start(100);
    connect(autoMoveTimer, SIGNAL(timeout()), this, SLOT(moveArmy()));
}


void InvaderArmy::paintArmy(QPainter &painter){
    for(int i=0; i<armyHeigth; i++){
        for(int j=0; j<armyWidth; j++){
            invaderArmy[i][j]->paintShip(painter);
        }
    }
}

int InvaderArmy::defEdgeLeft(int leftEdgeI){
    for(int j=0; j<armyHeigth; j++){
        if(invaderArmy[j][leftEdgeI]->getIsAlive()){
            return leftEdgeI;
        }
    }
    leftEdgeP += intervalShip;
    if(leftEdgeI+1<armyWidth) return defEdgeLeft(leftEdgeI+1);
    else{
        end = true;
        return fin;
    }
}

int InvaderArmy::defEdgeRight(int rightEdgeI){
    for(int j=0; j<armyHeigth; j++){
        if(invaderArmy[j][rightEdgeI]->getIsAlive()){
            rightEdgeP = invaderArmy[j][rightEdgeI]->pos.x();
            return rightEdgeI;
        }
    }
    //rightEdgeP = ;
    if(rightEdgeI-1>0) return defEdgeRight(rightEdgeI-1);
    else{
        end = true;
        return fin;
    }
}

int InvaderArmy::defEdgeBottom(int bottomEdgeI){
    for(int j=0; j<armyWidth; j++){
        if(invaderArmy[bottomEdgeI][j]->getIsAlive()){
            return bottomEdgeI;
        }
    }
    bottomEdgeP -= intervalRow;
    if(bottomEdgeI-1>0) return defEdgeBottom(bottomEdgeI-1);
    else{
        end = true;
        return fin;
    }
}

void InvaderArmy::moveArmy(){
    ++ timerCount;
    if(goLeft){
        leftEdgeI = defEdgeLeft(leftEdgeI);
        if(leftEdgeI != -1){
            if(leftEdgeP - dxarmy > xmin)
                for(int i=0; i<armyHeigth; i++)
                    for(int j=0; j<armyWidth; j++)
                        invaderArmy[i][j]->translate(-dxarmy, 0);
        }
        else{
            goLeft = false;
            goRight = true;
        }
    }
    if(goRight){
        rightEdgeI = defEdgeRight(rightEdgeI);
        cout << "rightEdgeI: " << rightEdgeI << endl;
        cout << "rightEdgeP: " << rightEdgeP << endl;
        if(rightEdgeI != -1){
            if(rightEdgeP + dxarmy < xmax){
                cout << "xmax: " << xmax << ", dxarmy: " << dxarmy << endl;
                for(int i=0; i<armyHeigth; i++)
                    for(int j=0; j<armyWidth; j++)
                        invaderArmy[i][j]->translate(+dxarmy, 0);

            }
        }
        else{
            goLeft = true;
            goRight = false;
        }
    }
}


bool InvaderArmy::isHit(QRect shot){
    cout << "avant le BOOMARMY" << endl;
    for(int i=0; i<armyHeigth; i++)
        for(int j=0; j<armyWidth; j++)
            if(invaderArmy[i][j]->isHit(shot)){
                cout << "KABLOOY" << endl;
                return true;
            }
    return false;
}
