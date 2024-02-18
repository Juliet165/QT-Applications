#include <time.h>
#include "tictactoe.h"
#include <QApplication>
#include <QIcon>


int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    int s = 5;
    TicTacToe w(nullptr, s);
    w.setStyleSheet("background-color : #F5F5F5;");
    w.setWindowTitle("Tic Tac Toe");
    w.setWindowIcon(QIcon("icon.jpg"));
    w.show();
    return a.exec();
}
