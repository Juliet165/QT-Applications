#include "game.h"
#include "topten.h"
#include <time.h>
#include <QApplication>
#include <QIcon>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(NULL));
    topTen rat;
    Game w(&rat);
    w.setWindowIcon(QIcon("cow.png"));
    rat.setWindowIcon(QIcon("ranking.png"));
    w.setFixedSize(800, 800);
    w.show();
    return a.exec();
}
