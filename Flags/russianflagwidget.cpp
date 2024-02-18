
#include "russianflagwidget.h"
#include <QPainter>

russianFlagWidget::russianFlagWidget(QWidget *parent)
    : QWidget{parent}
{

}

void russianFlagWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBrush clear(qRgb(190, 190, 190));
    painter.fillRect(0, 0,this->width(), this->height(), clear);
    QBrush brush(qRgb(255, 255, 255));
    QBrush brush1(qRgb(0, 57, 166));
    QBrush brush2(qRgb(213, 43, 30));
    if (3 * this->width() / 5 <= this->height())
    {
        qreal a = this->width();
        painter.fillRect(0, (this->height() - 3*a/5)/2, a, a/5+1, brush);
        painter.fillRect(0, (this->height())/2 - a/10, a, a/5+1, brush1);
        painter.fillRect(0, (this->height())/2 + a/10, a, a/5, brush2);
    }
    else
    {
        qreal a = 5*this->height()/3;
        painter.fillRect((this->width()-a)/2, 0, a, a/5+1, brush);
        painter.fillRect((this->width()-a)/2, a/5, a, a/5+1, brush1);
        painter.fillRect((this->width()-a)/2, 2*a/5, a, a/5, brush2);
    }

}
