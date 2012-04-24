#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <iostream>

QT_BEGIN_NAMESPACE
class QLCDNumber;
QT_END_NAMESPACE
class BattleField;

using namespace std;

namespace Ui {
class GameBoard;
}

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = 0);
    ~GameBoard();


protected slots:
    void newGame();
    void pause();
    void stop();

private:
    Ui::GameBoard *ui;
    QLCDNumber *hits;
    QLCDNumber *missed;
    QLCDNumber *timeLeft;
    BattleField *battleField;
};

#endif // GAMEBOARD_H
