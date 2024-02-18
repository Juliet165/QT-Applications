
#include "germanflagwidget.h"
#include <QPainter>
germanFlagWidget::germanFlagWidget(QWidget *parent)
    : QWidget{parent}
{

}
void germanFlagWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBrush clear(qRgb(196, 191, 192));
    painter.fillRect(0, 0,this->width(), this->height(), clear);
    QBrush brush(qRgb(0, 0, 0));
    QBrush brush1(qRgb(215, 30, 0));
    QBrush brush2(qRgb(248, 201, 0));
    if (3 * this->width() / 5 <= this->height())
    {
        qreal a = this->width();
        painter.fillRect(0, (this->height() - 3*a/5)/2, a, a/5+1, brush);
        painter.fillRect(0, (this->height() - 3*a/5)/2 + a/5, a, a/5+1, brush1);
        painter.fillRect(0, (this->height() - 3*a/5)/2 + 2*a/5, a, a/5, brush2);
    }
    else
    {
        qreal a = 5*this->height()/3;
        painter.fillRect((this->width()-a)/2, 0, a, a/5+1, brush);
        painter.fillRect((this->width()-a)/2, a/5, a, a/5+1, brush1);
        painter.fillRect((this->width()-a)/2, 2*a/5, a, a/5, brush2);
    }

}
