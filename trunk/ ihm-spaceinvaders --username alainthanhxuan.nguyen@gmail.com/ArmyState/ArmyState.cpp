#include "ArmyState.h"
#include <QPixmap>
#include <iostream>

using namespace std;

ArmyState::ArmyState(QObject *parent){
    animationTimer = new QTimer(parent);
    connect(animationTimer,SIGNAL(timeout()),this,SLOT(animationSlot()));
    cout<<"lfdsqfqsdfdvdqgq";
}

ArmyState::~ArmyState(){}

QPixmap ArmyState::getPixMap(){
    return NULL;
}

int ArmyState::getHeight(){
    return 0;
}

int ArmyState::getWidth(){
    return 0;
}

void ArmyState::animationSlot(){
}
