#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QShortcut>
#include <QVBoxLayout>
#include <QWidget>

#include "gameboard.h"
#include "ui_gameboard.h"
#include "battleField.h"
#include "lcdrange.h"

GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameBoard)
{
    ui->setupUi(this);

    QPushButton *quit = new QPushButton(tr("&Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QFrame *battleBox = new QFrame;

    battleBox->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);



    battleField = new BattleField;

    QPushButton *shoot = new QPushButton(tr("&Shoot"));
    shoot->setFont(QFont("Times", 18, QFont::Bold));

    connect(shoot, SIGNAL(pressed()), battleField, SLOT(fire()));

    QPushButton *left = new QPushButton(tr("&Left"));
    left->setFont(QFont("Times", 18, QFont::Bold));

    connect(left, SIGNAL(pressed()), battleField, SLOT(goLeft()));

    QPushButton *right= new QPushButton(tr("&Right"));
    right->setFont(QFont("Times", 18, QFont::Bold));

    connect(right, SIGNAL(pressed()), battleField, SLOT(goRight()));

    QPushButton *pause= new QPushButton(tr("&Pause"));
    pause->setFont(QFont("Times", 18, QFont::Bold));

    connect(pause, SIGNAL(clicked()), this, SLOT(pause()));

    QPushButton *stop= new QPushButton(tr("&Stop"));
    stop->setFont(QFont("Times", 18, QFont::Bold));

    connect(stop, SIGNAL(clicked()), this, SLOT(stop()));

    QPushButton *restart = new QPushButton(tr("&New Game"));
    restart->setFont(QFont("Times", 18, QFont::Bold));

    connect(restart, SIGNAL(clicked()), this, SLOT(newGame()));

    hits = new QLCDNumber(2);
    hits->setSegmentStyle(QLCDNumber::Filled);

    missed = new QLCDNumber(2);
    missed->setSegmentStyle(QLCDNumber::Filled);

    timeLeft = new QLCDNumber(2);
    timeLeft->setSegmentStyle(QLCDNumber::Filled);

    QLabel *hitsLabel = new QLabel(tr("HITS"));
    QLabel *missedLabel = new QLabel(tr("MISSED"));
    QLabel *timeLeftLabel = new QLabel(tr("TIME LEFT"));


    (void) new QShortcut(Qt::Key_Space, battleField, SLOT(fire()));

    (void) new QShortcut(Qt::Key_Left, battleField, SLOT(goLeft()));

    (void) new QShortcut(Qt::Key_Right, battleField, SLOT(goRight()));

    (void) new QShortcut(Qt::Key_P, this, SLOT(pause()));

    (void) new QShortcut(Qt::Key_S, this, SLOT(stop()));

    (void) new QShortcut(Qt::Key_N, this, SLOT(newGame()));

    (void) new QShortcut(Qt::Key_X, this, SLOT(close()));


    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addStretch(1);
    topLayout->addWidget(restart);
    topLayout->addWidget(pause);
    topLayout->addWidget(stop);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(hitsLabel);
    leftLayout->addWidget(hits);
    leftLayout->addWidget(missedLabel);
    leftLayout->addWidget(missed);
    leftLayout->addWidget(timeLeftLabel);
    leftLayout->addWidget(timeLeft);


    QVBoxLayout *battleLayout = new QVBoxLayout;

    battleLayout->addWidget(battleField);
    battleBox->setLayout(battleLayout);

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addLayout(topLayout, 0, 1);
    gridLayout->addLayout(leftLayout, 1, 0);
    gridLayout->addWidget(battleBox, 1, 1, 2, 1);
    gridLayout->setColumnStretch(1, 10);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(left);
    bottomLayout->addWidget(shoot);
    bottomLayout->addWidget(right);

    gridLayout->addLayout(bottomLayout, 3, 1);

    setLayout(gridLayout);

    newGame();
}



GameBoard::~GameBoard()
{
    delete ui;
}

void GameBoard::newGame()
{
    cout << "newGame" << endl;
    hits->display(0);
    battleField->restartGame();
    //battleField->newTarget();
    battleField->newPlayer();
}

void GameBoard::pause(){
    cout << "pause" << endl;
}

void GameBoard::stop(){
    cout << "stop" << endl;
}


