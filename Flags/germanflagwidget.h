
#ifndef GERMANFLAGWIDGET_H
#define GERMANFLAGWIDGET_H


#include <QWidget>

class germanFlagWidget : public QWidget
{
    Q_OBJECT
public:
    explicit germanFlagWidget(QWidget *parent = nullptr);
    void paintEvent (QPaintEvent* painter);
signals:

};

#endif // GERMANFLAGWIDGET_H
