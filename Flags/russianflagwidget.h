
#ifndef RUSSIANFLAGWIDGET_H
#define RUSSIANFLAGWIDGET_H


#include <QWidget>


class russianFlagWidget : public QWidget
{
    Q_OBJECT
public:
    explicit russianFlagWidget(QWidget *parent = nullptr);
    void paintEvent (QPaintEvent* painter);

signals:

};

#endif // RUSSIANFLAGWIDGET_H
