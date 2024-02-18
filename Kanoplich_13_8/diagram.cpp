
#include "diagram.h"
#include <time.h>
#include <QWidget>
#include <QtWidgets>

Diagram::Diagram(QWidget *parent)
    : QWidget{parent}
{
    srand(time(NULL));
    for (int i = 0; i < 5; ++i){
        QVector <int> temp;
        for (int j = 0; j < 5; ++j){
            int n = 1 + rand() % 10;
            temp.append(n);
        }
        nums.append(temp);
    }
}

void Diagram::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QBrush clear(qRgb(190, 190, 190));
    painter.fillRect(0, 0,this->width(), this->height(), clear);
    br = new QBrush(brushColor);
    painter.setBrush(*br);

    pen.setColor(penColor);
    painter.setPen(pen);
    qreal w = this->width();
    qreal h = this->height();
    int size = nums.size();
    int spaceX = w/20;
    int spaceY = h/20;
    if (size == 0){
        return;
    }
    qreal hd = h/(size+2*size+1);
    QFont font = painter.font();
    font.setPixelSize(hd);
    painter.setFont(font);

    qreal wReal = w-spaceX*2;
    qreal y = spaceY;
    qreal x = spaceX;
    for (int i = 0; i < size; ++i){
        x = spaceX;
        int sum = 0;
        for (int j = 0; j < size; ++j) {
            sum +=nums[i][j];
        }
        qreal ed = wReal/sum;
        for (int j = 0; j < size; ++j) {
            QRect rectan(x, y, ed*nums[i][j], hd*2);
            painter.fillRect(rectan, *br);
            painter.drawRect(rectan);
            QRect re(x, y, ed*nums[i][j], hd*2);
            painter.drawText(re,Qt::AlignCenter, QString::number(nums[i][j]));
            x+=ed*nums[i][j];
        }
        y+=3*hd;
    }

}

bool Diagram::openGraph(QString name){
    bool fine = false;
    QFile file(name);
    if(file.open(QIODevice::ReadOnly))
    {
        nums.clear();
        QDataStream fin(&file);
        int w;
        fin >> w;
        pen.setWidth(w);

        fin >> penColor;
        fin >> brushColor;

        QVector <int> temp;
        while(!fin.atEnd())
        {
            int x;
            fin >> x;
            temp.append(x);
        }
        int s = sqrt(temp.size());
        int r = 0;
        for(int i = 0; i < s; i++)
        {
            QVector <int> temp2;
            for(int j = 0; j < s; j++)
            {
                temp2.append(temp[r]);
                r++;
            }
            nums.append(temp2);
        }
        fine = true;
    }
    file.close();
    update();
    return fine;
}

bool Diagram::saveImg(const QString &fileName)
{
    bool fine = false;
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream fout(&file);
        fout << pen.width();
        fout << penColor;
        fout << brushColor;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                fout << nums[i][j];
            }
        }
        fine = true;
    }
    file.close();
    return fine;
}
