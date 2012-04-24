#include <QtGui/QApplication>
#include "gameboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameBoard board;
    board.setGeometry(50, 50, 600, 600);
    board.show();
    
    return a.exec();
}
