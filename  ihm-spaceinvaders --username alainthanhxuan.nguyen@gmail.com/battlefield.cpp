#include <QDateTime>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

#include <math.h>
#include <stdlib.h>

#include "battlefield.h"

BattleField::BattleField(QWidget *parent)
    : QWidget(parent)
{
    timerCount = 0;
    autoShootTimer = new QTimer(this);

    target = QPoint(0, 0);
    gameEnded = false;

    setPalette(QPalette(QColor(255, 255, 255)));
    setAutoFillBackground(true);
}


void BattleField::restartGame()
{
    update();
    timerCount = 0;
    autoShootTimer = new QTimer(this);
}

void BattleField::newPlayer(){
    int x = this->width();
    int y =this->height();

    playerShip = new PlayerShip(x, y, this);
    //invaderShip = new InvaderShip(x, y);
    invaderArmy = new InvaderArmy(x, y);
}


void BattleField::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    playerShip->paintShip(painter);

    if(playerShip->isShooting()){
        playerShip->bullet->paintShot(painter);
    }

    /*if(invaderShip != NULL){
        invaderShip->paintShip(painter);
    }*/

    if(!invaderArmy->end){
        invaderArmy->paintArmy(painter);
    }

    update();
}


void BattleField::goLeft(){
    cout << "goLeftBattle" << endl;
    playerShip->goLeft();
}

void BattleField::goLeft(QKeyEvent *e){
    cout << "goLeftBattle" << endl;
    while(e->isAutoRepeat()){
        playerShip->goLeft();
    }
}

void BattleField::goRight(){
    cout << "goRightBattle" << endl;
    playerShip->goRight();
}

void BattleField::goRight(QKeyEvent* e){
    cout << "goRightBattle" << endl;
    while(e->isAutoRepeat()){
        playerShip->goRight();
    }
}

void BattleField::fire(){
    cout << "fireBattle" << endl;
    playerShip->fireShot();
}

bool BattleField::isHit(QRect shot){
    cout << "avant le BOUMBATTLE" << endl;
    ++ timerCount;

    /*if(shot.intersects(invaderShip->invader)){
        cout << "BOUM" << endl;
        autoShootTimer->stop();
        invaderShip->setIsAlive(false);

        delete(invaderShip);
        invaderShip = NULL;
        //emit hit();
        //detruire l'invaderShip en question
        //emit playerShip->canShoot(true);

        return true;
    }
    else if(shot.y() < 0){
        cout << "MISSED" << endl;
        autoShootTimer->stop();
        emit missed();
        //emit playerShip->canShoot(true);
        return true;
    }*/
    return false;
}


void BattleField::beginTimer(){
    timerCount = 0;
    autoShootTimer->start(5);
}


int BattleField::getSizeX(){
    return this->width();
}

int BattleField::getSizeY(){
    return this->height();
}
