#include "ArmyState.h"
#include <QPixmap>
#include <iostream>
#include <QString>

using namespace std;

ArmyState::ArmyState(QObject *parent){
    name = "AbstractState";
    animationTimer = new QTimer(parent);
    connect(animationTimer,SIGNAL(timeout()),this,SLOT(animationSlot()));
}

ArmyState::~ArmyState(){
    delete animationTimer;
}

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

QString ArmyState::getClassName(){
    return name;
}
