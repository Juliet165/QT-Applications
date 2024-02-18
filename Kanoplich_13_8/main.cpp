
#include "sdi.h"
#include <time.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sdi w;
    srand(time(NULL));
    w.setWindowTitle("Каноплич Юлия");
    //w.setWindowIcon(QIcon("icon.png"));
    w.show();
    return a.exec();
}
