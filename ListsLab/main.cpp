
#include "listwidget.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListWidget w;
    w.setFixedSize(1200, 1000);
    w.setWindowIcon(QIcon("iconList.jpg"));
    w.setStyleSheet("background-color : #fe876;"); //#f2e9d0
    w.show();
    return a.exec();
}
